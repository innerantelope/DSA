class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int tg=(sum+target)/2;
        if((target+sum)%2!=0 || abs(target)>sum) return 0;
        vector<int>dp(tg+1,0);
        dp[0]=1;
        for(int num:nums){
            for(int i=tg;i>=num;i--){
                dp[i]+=dp[i-num];
            }
        }
        return dp[tg];
    }
};