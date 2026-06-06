class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        if(nums.size()==1) return {0};
        vector<int>ls(nums.size(),0);
        vector<int>rs(nums.size(),0);
        vector<int>ans(nums.size(),0);
        for(int i=1;i<nums.size()-1;i++){
            ls[i]=ls[i-1]+nums[i-1];
            rs[nums.size()-i-1]=rs[nums.size()-i]+nums[nums.size()-i];
        }
        rs[0]=rs[1]+nums[1];
        ls[nums.size()-1]=ls[nums.size()-2]+nums[nums.size()-2];
        for(int i=0;i<nums.size();i++){
            ans[i]=abs(ls[i]-rs[i]);
        }
        return ans;
        
    }
};