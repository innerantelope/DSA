class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=nums[0];
        int maxi=nums[0];
        int minisum=nums[0];
        int currmax=nums[0];
        int currmin=nums[0];
        for(int i=1;i<nums.size();i++){
            currmax=max(nums[i],currmax+nums[i]);
            maxi=max(maxi,currmax);
            currmin=min(currmin+nums[i],nums[i]);
            minisum=min(minisum,currmin);
            total+=nums[i];
        }
        if(maxi<0) return maxi;

        return max(maxi,total-minisum);

        
    }
};