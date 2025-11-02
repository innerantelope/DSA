class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> vis(m,vector<int>(n,0));

        for (auto &g : guards) grid[g[0]][g[1]] = 1;
        for (auto &w : walls) grid[w[0]][w[1]] = 2;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

         for (auto &g : guards) {
            int x = g[0], y = g[1];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];

                while (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 1 && grid[nx][ny] != 2) {
                    vis[nx][ny] = 1;
                    nx += dx[d];
                    ny += dy[d];
                }
            }
        }

        int guarded = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 1) guarded++;
            }
        }

        return m*n - (guards.size() + walls.size() + guarded);





        
    }
};