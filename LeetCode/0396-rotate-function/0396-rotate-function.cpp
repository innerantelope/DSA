class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int>pref_sum(nums.size());
        pref_sum[0]=0;
        for(int i=1;i<nums.size();i++){
            pref_sum[i]=pref_sum[i-1]+(long long)i*nums[i];
        }
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        vector<int>ans(nums.size());
        ans[0]=pref_sum[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            ans[i]=ans[i-1]+(sum-(nums.size())*nums[nums.size()-i]);
        }

        return *max_element(ans.begin(),ans.end());

        
    }
};