class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> mark(n, 0);
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1] + 1) mark[i] = 1;
        }

        vector<int> ans(n - k + 1);

        int bad = 0;
        for(int i = 1; i < k; i++){
            bad += mark[i];
        }

        ans[0] = (bad == 0 ? nums[k-1] : -1);

        for(int i = 1; i <= n - k; i++){
            bad -= mark[i];
            bad += mark[i + k - 1];

            ans[i] = (bad == 0 ? nums[i + k - 1] : -1);
        }

        return ans;
    }
};