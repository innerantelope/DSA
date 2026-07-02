class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> best(m, vector<int>(n, -1));
        priority_queue<vector<int>> pq;
        int start = health - grid[0][0];
        if (start < 1) return false;
        pq.push({start, 0, 0});
        best[0][0] = start;
        vector<pair<int,int>> dir = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int h = cur[0];
            int x = cur[1];
            int y = cur[2];
            if (x == m - 1 && y == n - 1) return true;
            for (auto &d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                int nh = h - grid[nx][ny];
                if (nh < 1) continue;
                if (best[nx][ny] >= nh) continue;
                best[nx][ny] = nh;
                pq.push({nh, nx, ny});
            }
        }

        return false;
    }
};