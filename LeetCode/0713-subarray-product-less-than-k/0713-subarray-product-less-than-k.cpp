class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int left=0;
        int right=0;
        if(k<=1) return 0;
        long long prod=1;
          for(int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while(prod >= k) {
                prod /= nums[left];
                left++;
            }
            ans += (right - left + 1);
        }
         return ans;
        
    }
};