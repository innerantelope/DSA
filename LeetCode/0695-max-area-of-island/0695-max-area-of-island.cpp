class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>&vis,int i,int j,int m,int n){
        vis[i][j]=1;
        int area=1;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++){
            int dr=i+dir[k][0];
            int dy=j+dir[k][1];
            if(dr>=0 && dy>=0 && dr<m && dy<n && !vis[dr][dy] && grid[dr][dy]==1 ){
                area+=dfs(grid,vis,dr,dy,m,n);
            }

        }
        return area;
    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int area=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    area=dfs(grid,vis,i,j,m,n);
                    maxi=max(maxi,area);

                }
            }
        }
        return maxi;
        
    }
};