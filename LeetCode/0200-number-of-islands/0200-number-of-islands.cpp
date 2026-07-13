class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>&vis,int i,int j,int m,int n){
        vis[i][j]=1;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++){
            int dr=i+dir[k][0];
            int dy=j+dir[k][1];
            if(dr>=0 && dy>=0 && dr<m && dy<n && !vis[dr][dy] && grid[dr][dy]=='1' ){
                dfs(grid,vis,dr,dy,m,n);
            }

        }
    
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,vis,i,j,m,n);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};