class Solution {
public:
    int dp[201][10001];
    bool cps(vector<int>&nums,int i,int target){
        if(target==0) return true;
        if(i >= nums.size() || target < 0) return false;
        if(dp[i][target] != -1) return dp[i][target];
        return dp[i][target]= cps(nums, i+1, target - nums[i]) || cps(nums, i+1, target);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        memset(dp, -1, sizeof(dp));
        return cps(nums,0,sum/2);
       
    }
};