class Solution {
public:
    int solve(vector<int>&nums,int target,int n){
        if(n==nums.size()) return (target==0)?1:0;
        int countp=solve(nums,target-(nums[n]),n+1);
        int counneg=solve(nums,target-(-nums[n]),n+1);
        return countp+counneg;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=solve(nums,target,0);
        return ans;
           
    }
};