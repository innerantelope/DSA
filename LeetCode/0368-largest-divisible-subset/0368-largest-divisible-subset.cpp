class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int maxi=1;
        int li=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                    if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                    li=i;
                }
            }
        }
        vector<int>ans;
        while(li!=-1){
            ans.push_back(nums[li]);
            li=parent[li];
        }

        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};