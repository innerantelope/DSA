class Solution {
public:
    int dp[1001][1001];
    int ls(int i,int j,vector<int>& nums){
        if (j==0) return 0;
        if (i>=nums.size() || j<0) return INT_MIN;
        if (dp[i][j]!=-1) return dp[i][j];
        int p=ls(i+1,j-nums[i],nums);
        if (p!=INT_MIN) p++;
        int np=ls(i+1,j,nums);
        return dp[i][j]=max(p,np);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=ls(0,target,nums);
        if (ans==INT_MIN) ans=-1;
        return ans;
        
    }
};