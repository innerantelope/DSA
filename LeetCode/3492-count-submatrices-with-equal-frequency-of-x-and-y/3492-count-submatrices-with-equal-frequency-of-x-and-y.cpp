class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X') mat[i][j] = 1;
                else if(grid[i][j] == 'Y') mat[i][j] = -1;
                else mat[i][j] = 0;
            }
        }
        int ans = 0;
        vector<int> cols(m, 0);
        vector<int> countX(m, 0);
        for(int bottom = 0; bottom < n; bottom++) {
            for(int col = 0; col < m; col++) {
                cols[col] += mat[bottom][col];
                if(grid[bottom][col] == 'X') {
                    countX[col]++;
                }
            }
            int prefix = 0;
            int x_prefix = 0;
            for(int col = 0; col < m; col++) {
                prefix += cols[col];
                x_prefix += countX[col];
                if(prefix == 0 && x_prefix > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};