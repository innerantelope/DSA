class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum=0;
        long long ans=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
             if (i >= 2 && sum - nums[i] > nums[i]) {
                ans = max(ans, sum);
            }
           
        }
        return ans;
        
    }
};