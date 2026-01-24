class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sumi =nums[0]+nums[n-1];
        for(int i=1;i<n/2;i++){
            int x = nums[i]+nums[n-1-i];
            sumi=max(sumi,x);
        }
        return sumi;
    }
};