class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n,0);
        for(int j=0;j<n;j++){
            for(int i=0;i<j;i++){
                bool chk=true;
                for(int row=0;row<m;row++){
                    if(abs(grid[row][j]-grid[row][i])>limit){
                        chk=false;
                        break;
                    }
                }
                if(chk) dp[j]=max(dp[j],dp[i]+1);
            }

        }
        return *max_element(dp.begin(),dp.end())+1;
        
    }
};