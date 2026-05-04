/*
Motivation: Save the rows and cols to zero on the matrix itself.
    Loop over the matrix once, where a cell has the value 0, update the matrix
    first row and col coresponding position in the matrix.
    Finally go over the matrix again and zero any cell which is col or rows are marked. 
Complexity:
    Time - O(n*m): Looping over the matrix twice.
    Space - O(1): Using the matrix to store the flags.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        
        bool first_row_zero = false;
        bool first_col_zero = false;

        // read the matrix and mark first row and col
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) first_row_zero = true; 
                    if (j == 0) first_col_zero = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // write 0 according to first row and col
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // reset first row
        if (first_row_zero) {
            for (size_t j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        
        // reset first col
        if (first_col_zero) {
            for (size_t i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
