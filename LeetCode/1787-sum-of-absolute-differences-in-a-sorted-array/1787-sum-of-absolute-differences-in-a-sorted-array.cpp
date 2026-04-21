class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] + nums[i];
        }

        for(int i = 0; i < n; i++){
            int left = i * nums[i] - (i > 0 ? pref[i-1] : 0);
            int right = (pref[n-1] - pref[i]) - (n - i - 1) * nums[i];
            ans[i] = left + right;
        }

        return ans;
    }
};