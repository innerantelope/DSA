class Solution {
public:
    int n;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int t) {
        if (r < 0 || c < 0 || r >= n || c >= n) return false;
        if (vis[r][c] || grid[r][c] > t) return false;
        if (r == n-1 && c == n-1) return true;
        vis[r][c] = 1;
        for (auto &d : dirs) {
            int nr = r + d.first;
            int nc = c + d.second;   
            if (dfs(nr, nc, grid, vis, t)) return true;
        }
        return false;
    }
    
    bool canReach(vector<vector<int>>& grid, int t) {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        return dfs(0, 0, grid, vis, t);
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = 0, high = n*n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (canReach(grid, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};