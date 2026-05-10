class Solution {
public:
    int s[1001];
    int solve(int i,vector<int>&nums,int target){
        int n=nums.size();
        if(i==n-1) return 0;
        if(s[i]!=-2) return s[i];
        int ans=-1;
        for(int j=i+1;j<n;j++){
            if(abs(nums[j]-nums[i])<=target){
                int t=solve(j,nums,target);
                if(t!=-1){
                ans=max(ans,1+t);
            }
        }
        // if(nums[i+1]-nums[i]>=-target && nums[i+1]-nums[i]<=target){
        //     solve(i+1,nums,n,target,j+1);
        // }
        // else{
        //     solve(i+1,nums,n,target,j);
        // }
    }
    return s[i]=ans;
}
    int maximumJumps(vector<int>& nums, int target) {
        fill(s,s+1001,-2);
       return solve(0,nums,target);
    
    }
};