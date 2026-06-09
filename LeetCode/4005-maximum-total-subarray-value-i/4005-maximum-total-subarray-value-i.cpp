class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long x=*min_element(nums.begin(),nums.end());
        long long y=*max_element(nums.begin(),nums.end());
        return k*(y-x);
        
    }
};