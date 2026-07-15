class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        if(sum%2==1) return false;
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        for(int j=0;j<n;j++){
            dp[j][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(nums[i-1]<=j){
                    take=dp[i-1][j-nums[i-1]];
                }
                dp[i][j]=take||nottake;
            }
        }

        return dp[n][target];



    }
};