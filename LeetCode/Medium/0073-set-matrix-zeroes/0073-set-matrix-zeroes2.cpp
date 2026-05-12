/*
Motivation: Wildcard Marker.
    Find a random number that does not appear in the matrix (statistically
    O(1) since (n*m) / INT_RANGE is almost 0). Replace all original 0's with
    the wildcard. Then loop over the matrix and for each wildcard, zero its
    entire row and column without changing the wildcards.
    Finally set the wildcards back to 0.
Complexity: 
    Time - O((n*m)*(n+m)): For each wildcard we zero its row and column.
    Space - O(1): Modifying the matrix in place.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // fins a number that is not in the matrix
        int wildcard = find_non_matrix_value(matrix);
        
        // mark all 0's with the wildcard
        for (auto& row : matrix) {
            std::replace(row.begin(), row.end(), 0, wildcard);
        }

        // zero all rows and cols of a wildcard
        for (std::size_t row = 0; row < matrix.size(); ++row) {
            for (std::size_t col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == wildcard) {
                    zero_row_and_col(matrix, row, col, wildcard);
                }
            }
        }

        // zero back the wildcards
        for (auto& row : matrix) {
            std::replace(row.begin(), row.end(), wildcard, 0);
        }
    }

private:
    /* return true if the given number appears in the matrix. O(m*n) */
    static bool matrix_contains(vector<vector<int>> const& matrix, int const wildcard) {
        for (auto const& row : matrix) {
            if (std::find(row.begin(), row.end(), wildcard) != row.end()) {
                return true;
            }
        }
        return false;
    }

    /* find a number that not appears in the matrix. O(1) #loops */
    static int find_non_matrix_value(vector<vector<int>> const& matrix) {
        while (1) {
            int wildcard = rand();
            if (!matrix_contains(matrix, wildcard)) {
                return wildcard;
            }
        }
    }

    /* sets a number to 0 if its value is not the wildccard */
    static void set_if_not_wildcard(int& num, int const wildcard) {
        if (num != wildcard) {
            num = 0;
        }
    }

    /* set the row and col to zero if the value is not the wildcard */
    static void zero_row_and_col(vector<vector<int>>& matrix, std::size_t row, std::size_t col, int wildcard) {
        for (std::size_t i = 0; i < matrix.size(); ++i) {
            set_if_not_wildcard(matrix[i][col], wildcard);
        }
        for (std::size_t j = 0; j < matrix[0].size(); ++j) {
            set_if_not_wildcard(matrix[row][j], wildcard);
        }
    }

};