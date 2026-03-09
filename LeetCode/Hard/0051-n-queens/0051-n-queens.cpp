/*
Motivation: Backtracking.
      Try to put a queen row by row.
      For each row, loop over every column and check if it's safe.
      Use boolean arrays to remember if a column or a diagonal is taken.
      If it's safe, put the queen, mark the arrays, and go to the next row.
      If we hit a dead end, backtrack and try the next column.
Complexity: 
    Time - O(n^n): In the decision tree we have n options for every option.
    Space - O(n): The boolean arrays size.
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        // vector to hold results
        vector<vector<string>> result;

        // sets to hold occupied rows or diagonals
        vector<bool> cols(n, false);
        vector<bool> pos_diag(2 * n, false);
        vector<bool> neg_diag(2 * n, false);

        vector<string> curr;

        // recursively search solutions
        findSolutions(result, curr, cols, pos_diag, neg_diag, 0, n);

        return result;        
    }

    void findSolutions(vector<vector<string>>& result,
                        vector<string>& curr,
                        vector<bool>& cols,
                        vector<bool>& pos_diag,
                        vector<bool>& neg_diag,
                        int i, int const n)
    {
        // found solution
        if (i == n) {
            result.push_back(curr);
            return;
        }

        // for every column
        for (int j = 0; j < n; ++j) {
            
            // valid position
            if ( !cols[j] && !pos_diag[i + j] && !neg_diag[i - j + n] ) {
                
                // save constrains
                cols[j] = true;
                pos_diag[i + j] = true;
                neg_diag[i - j + n] = true;

                // curr row
                string row(n, '.');
                row[j] = 'Q';
                curr.push_back(row);

                // try next row
                findSolutions(result, curr, cols, pos_diag, neg_diag, i + 1, n);
                
                // backtrack
                cols[j] = false;
                pos_diag[i + j] = false;
                neg_diag[i - j + n] = false;
                curr.pop_back();
            }
        }
    }
};
