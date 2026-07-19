class Solution {
public:

    bool issafe(vector<string>& board, int row, int col, int n) {

        // Check same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void getallcomb(int n, int row,
                    vector<vector<string>>& ans,
                    vector<string>& board) {

        // All queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing queen in every column
        for (int col = 0; col < n; col++) {

            if (issafe(board, row, col, n)) {

                board[row][col] = 'Q';      // Place queen

                getallcomb(n, row + 1, ans, board);

                board[row][col] = '.';      // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        getallcomb(n, 0, ans, board);

        return ans;
    }
};