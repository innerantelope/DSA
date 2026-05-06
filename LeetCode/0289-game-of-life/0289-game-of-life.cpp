class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> dir = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},{0,1},
            {1,-1},{1,0},{1,1}
        };
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int live = 0;
                for(int k = 0; k < 8; k++) {
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n) {
                        if(board[ni][nj] == 1 || board[ni][nj] == -1)
                            live++;
                    }
                }
                if(board[i][j] == 1) {
                    if(live < 2 || live > 3)
                        board[i][j] = -1;
                }
                else {
                    if(live == 3)
                        board[i][j] = 2; 
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};