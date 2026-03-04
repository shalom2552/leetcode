/*
Motivation: Backtracking.
    For each empty cell find all valid options and try them in order, 
    recursing to the next cell. If a cell has no options, backtrack to 
    the previous cell and try a different option.
Complexity:
    Time - O(9^(N*N)): In the worst case, we explore every option for every cells.
    Space - O(N*N): The recursion depth and the board.
*/

#define N 9

class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        (void) backtrack(board, 0);
    }

    bool backtrack(vector<vector<char>>& board, size_t idx)
    {
        // board is solved            
        if (idx == N * N) {
            return true;
        }

        // get cordinates from idx
        size_t i = idx / N;
        size_t j = idx % N;

        // skip prefilled cells
        if (board[i][j] != '.') {
            return backtrack(board, idx + 1);
        }

        // try all options for current cell
        for (char option : cell_options(board, i, j)) {
            
            // try current option
            board[i][j] = option;

            // traverse next cells
            if (backtrack(board, idx + 1)) {
                return true;
            }

            // backtrack
            board[i][j] = '.';
        }

        // no solution found
        return false;
    }

    vector<char> cell_options(vector<vector<char>>& board, size_t i, size_t j)
    {
        // start with all options
        vector<char> options = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        // check rows and coloms
        for (size_t idx = 0; idx < N; ++idx) {
            char row_cell = board[i][idx];
            char col_cell = board[idx][j];

            // remove conflicting values from options
            update_options(options, row_cell);
            update_options(options, col_cell);
        }

        // find current sub-box starting cell
        size_t start_row = (i / 3) * 3;
        size_t start_col = (j / 3) * 3;

        // check sub-box
        for (size_t idx_row = 0; idx_row < N / 3; ++idx_row) {
            for (size_t idx_col = 0; idx_col < N / 3; ++idx_col) {
                
                // get all cell [idx_row][idx_col] of current sub-box
                char box_cell = board[start_row + idx_row][start_col + idx_col];

                // remove conflicting value from options
                update_options(options, box_cell);
            }
        }

        return options;
    }

    // remove a number from the vector of options
    void update_options(vector<char>& options, char cell)
    {
        // only process numbers
        if (cell != '.') {
            
            // convert to int
            char to_remove = cell;

            // remove-erase
            auto it = std::remove(options.begin(), options.end(), to_remove);

            // earse if exist
            options.erase(it, options.end());
        }
    }

};