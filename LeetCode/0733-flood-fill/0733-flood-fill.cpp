class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];
        if (original == color) return image;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> q;

        q.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = color;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (!visited[nr][nc] && image[nr][nc] == original) {
                        visited[nr][nc] = true;
                        image[nr][nc] = color;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return image;
    }
};
