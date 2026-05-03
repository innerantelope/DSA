class Solution {
public:
    long long dfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&dir,int m,int n){
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(grid[i][j]==0) return 0;

        long long sum=0;
        sum+=grid[i][j];
        grid[i][j]=0;
        for(auto &d:dir){
            int dx=d[0]+i;
            int dy=d[1]+j;
            for(int k=0;k<4;k++){
                sum+=dfs(dx,dy,grid,dir,m,n);

            }

        }
    return sum;



    }


    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    long long val=dfs(i,j,grid,dir,m,n);
                    if(val%k==0) count++;
                }
            }
        }

        return count;
        
        
    }
};