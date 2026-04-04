class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        set<int> st;

        int last = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int low = nums[i] - k;
            int high = nums[i] + k;

            int val = max(last + 1, low);

            if (val <= high) {
                st.insert(val);
                last = val;
            }
        }

        return st.size();
    }
};