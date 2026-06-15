class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>&visited,int x,int y){
        visited[x][y]=true;
        int ans=0;
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        for(int k=0;k<4;k++){
            int nr=x+dir[k].first;
            int nc=y+dir[k].second;
            if(nr>=0 && nr<grid.size()&&nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1' && !visited[nr][nc]){
                dfs(grid,visited,nr,nc);

            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,visited,i,j);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};