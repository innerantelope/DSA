class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int layers=min(m/2,n/2);
        for(int layer=0;layer<layers;layer++){
            vector<int>ans;
            int top=layer;
            int bottom=m-layer-1;
            int left=layer;
            int right=n-layer-1;
            for(int j=left;j<=right;j++){
                ans.push_back(grid[top][j]);
            }
            for(int j=top+1;j<=bottom-1;j++){
                ans.push_back(grid[j][right]);
            }
            for(int j=right;j>=left;j--){
                ans.push_back(grid[bottom][j]);
            }
            for(int j=bottom-1;j>=top+1;j--){
                ans.push_back(grid[j][left]);
            }
            int len=ans.size();
            int s=k%len;
            rotate(ans.begin(),ans.begin()+s,ans.end());
             int idx = 0;

            for (int j = left; j <= right; j++) {
                grid[top][j] = ans[idx++];
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = ans[idx++];
            }

            for (int j = right; j >= left; j--) {
                grid[bottom][j] = ans[idx++];
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = ans[idx++];
            }
    
            

            
        }
        return grid;
        

        
    }
};