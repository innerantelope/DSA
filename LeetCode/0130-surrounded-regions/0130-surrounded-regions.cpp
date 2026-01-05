class Solution {
private:
    void dfs(int i, int j,
             vector<vector<int>>& visited,
             vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        visited[i][j] = 1;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n &&
               board[ni][nj] == 'O' && visited[ni][nj] == 0) {
                dfs(ni, nj, visited, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        // first row
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, visited, board);
        }

        // last row
        for(int j = 0; j < n; j++) {
            if(board[m-1][j] == 'O' && !visited[m-1][j])
                dfs(m-1, j, visited, board);
        }

        // first column
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, visited, board);
        }

        // last column
        for(int i = 0; i < m; i++) {
            if(board[i][n-1] == 'O' && !visited[i][n-1])
                dfs(i, n-1, visited, board);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
