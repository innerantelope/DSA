class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board, result); // Start from row 0
        return result;
    }

private:
    void backtrack(int row, int n, vector<string>& board,
                   vector<vector<string>>& result) {
        // base case
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';                // place queen
                backtrack(row + 1, n, board, result); // move to next row
                board[row][col] = '.';                // remove queen (backtrack)
            }
        }
    }

    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column 
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal 
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
};
