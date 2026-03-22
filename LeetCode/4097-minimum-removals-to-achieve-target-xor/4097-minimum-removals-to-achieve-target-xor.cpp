class Solution {
public:
    vector<unordered_map<int,int>> dp;
    int solve(vector<int>&nums,int target,int n,int curr){
        if(n==nums.size()){
            if(curr==target) return 0;
            return 1e9;
        }
        if (dp[n].count(curr)) return dp[n][curr];
        // int ans=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     ans=ans^nums[i];
        // }
    //     if(ans==target) return 0;
    //    if(solve(nums,target,n+1)){
    //     ans=ans^nums[n];
       
    //    }
    //    else solve(nums,target,n+1);
    int k=solve(nums,target,n+1,curr^nums[n]);
    int p=1+solve(nums,target,n+1,curr);

    return dp[n][curr]=min(k,p);

    }
    int minRemovals(vector<int>& nums, int target) {
        int x=nums.size();
        dp.resize(x);
        int res=solve(nums,target,0,0);
        return (res >= 1e9 ? -1 : res);
        
    }
};