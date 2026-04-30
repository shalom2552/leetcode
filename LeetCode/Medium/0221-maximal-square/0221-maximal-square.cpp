/*
Motivation: Dynamic programming.
    We loop through the matrix, and if the cell is '1', we check the
    top, left, and diagonal cells. For the first row or column we just
    set it to 1. We take the min of these three neighbors, add 1, and
    keep track of the max side length on the fly.
Complexity: 
    Time - O(m * n): going through every cell in the matrix.
    Space - O(m * n): using an extra 2D vector for the dp table.
Space could be improved to O(n), by tracking only the current and prev rows. 
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        // initialize the dp with 0`s
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // buttom up build the dp
        int max_side = 0;  // find max on the fly
        for (size_t row = 0; row < m; ++row) {
            for (size_t col = 0; col < n; ++col) {
                // skip 0 cells - cant have max squere there
                if (matrix[row][col] == '0') continue;

                // for first row or column
                if (row == 0 || col == 0) {
                    // just set to 1
                    dp[row][col] = 1;
                } else {
                    // add one to current squere
                    int top = dp[row - 1][col];
                    int diag = dp[row - 1][col - 1];
                    int left = dp[row][col - 1];
                    dp[row][col] = 1 + min(min(top, left), diag);
                }
                // update max side on the fly
                max_side = max(max_side, dp[row][col]);
            }
        }
        
        // max squre is side squared
        return max_side * max_side;
    }
};
