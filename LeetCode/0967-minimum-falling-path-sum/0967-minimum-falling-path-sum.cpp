class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //dp[i][j]=state will define that max falling cost till i,j
        //i+1,j
        //i+1,j+1,
        //i+1,j-1,
        // I will start from filling the table from the last row
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<n;i++){
            dp[m-1][i]=matrix[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                dp[i][j]=min(dp[i+1][j],min(j<n-1?dp[i+1][j+1]:INT_MAX,j>0?dp[i+1][j-1]:INT_MAX))+matrix[i][j];

            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(dp[0][i]<mini) mini=dp[0][i];
        }
        return mini;
    }
};