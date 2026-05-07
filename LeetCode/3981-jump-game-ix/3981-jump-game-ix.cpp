class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        vector<int>pre_max(nums.size());
        vector<int>suff_min(nums.size());
        pre_max[0]=nums[0];
        suff_min[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            pre_max[i]=max(pre_max[i-1],nums[i]);
            suff_min[nums.size()-i-1]=min(suff_min[nums.size()-i],nums[nums.size()-i-1]);
        }
        vector<int>ans(nums.size());
        ans[nums.size()-1]=pre_max[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(pre_max[i]>suff_min[i+1]){ 
                ans[i]=ans[i+1];
            }
            else ans[i]=pre_max[i];
        }

        return ans;


        
    }
};