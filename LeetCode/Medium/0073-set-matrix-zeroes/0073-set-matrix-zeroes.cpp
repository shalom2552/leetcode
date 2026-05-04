/*
Motivation: Save the rows and cols to zero.
    Loop over  the matrix once, where a cell has the value 0, update its row and col
    position in the coresponding vector.
    Finally go over the matrix again and zero any cell which is col or rows are marked. 
Complexity:
    Time - O(n*m): Looping over the matrix twice.
    Space - O(n+m): Vectors for the row and colmns.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        
        vector<bool> rows_zero(m, false);
        vector<bool> cols_zero(n, false);

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows_zero[i] = true;
                    cols_zero[j] = true;
                }
            }
        }
        
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (rows_zero[i] || cols_zero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
