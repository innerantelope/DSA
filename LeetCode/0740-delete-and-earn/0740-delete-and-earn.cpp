class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int i:nums){
            freq[i]++;
        }
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>ans(mx+1,0);
        for(int i=0;i<=mx;i++){
            ans[i]=i*freq[i];
        }
        vector<int> dp(mx + 1,0);
        dp[0]=0;
        dp[1]=ans[1];
        for(int i=2;i<=mx;i++){
            dp[i]=max(dp[i-1],dp[i-2]+ans[i]);

        }

        return dp[mx];

        
    }
};