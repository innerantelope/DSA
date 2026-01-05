class Solution {
private:
    void dfs(int i, int j,vector<vector<int>>& visited,vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        visited[i][j] = 1;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n &&
               grid[ni][nj] == 1 && visited[ni][nj] == 0) {
                dfs(ni, nj, visited, grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        int land_cell =0;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // first row
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1 && !visited[0][j])
                dfs(0, j, visited, grid);
        }

        // last row
        for(int j = 0; j < n; j++) {
            if(grid[m-1][j] == 1 && !visited[m-1][j])
                dfs(m-1, j, visited, grid);
        }

        // first column
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1 && !visited[i][0])
                dfs(i, 0, visited, grid);
        }

        // last column
        for(int i = 0; i < m; i++) {
            if(grid[i][n-1] == 1 && !visited[i][n-1])
                dfs(i, n-1, visited, grid);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]) land_cell++;
            }
        }

      return land_cell;

        
    }
};