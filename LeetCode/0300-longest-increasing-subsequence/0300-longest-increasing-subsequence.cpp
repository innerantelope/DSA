class Solution {
public:
    // int solve(vector<int>&nums,int x,int prev,vector<vector<int>>& dp){
    //     if(x==nums.size()) return 0;
    //     if(dp[x][prev+1]!=-1) return dp[x][prev+1];
    //     int nk= solve(nums,x+1,prev,dp);
    //     int tk=0;
    //     if(prev==-1 || nums[x]>nums[prev]){
    //        tk=1+solve(nums,x+1,x,dp);
    //     }
    //     return dp[x][prev+1]=max(tk,nk);
    // }
        
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(nums,0,-1,dp);  
        vector<int>ans;
        for(int x:nums){
            auto it= lower_bound(ans.begin(),ans.end(),x);
            if(it==ans.end()){
                ans.push_back(x);
            }
            else{
                *it=x;
            }

        }    
        return ans.size();
    }
};