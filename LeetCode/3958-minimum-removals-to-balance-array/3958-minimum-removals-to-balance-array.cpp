class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
         int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int maxi = 1;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            while (left <= right && (long long)nums[right] > (long long)k * nums[left]) {
                left++;
            }
            
            if (left <= right) {
                maxi = max(maxi, right - left + 1);
            }
        }
        
        return n - maxi;
        
    }
};