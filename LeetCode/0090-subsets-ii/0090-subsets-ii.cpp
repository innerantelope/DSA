class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        backtrack(0, nums, current, result);
        return result;
    }

    void backtrack(int i, vector<int>& nums, vector<int>& current,
                   vector<vector<int>>& result) {
        result.push_back(current);

        for (int index = i; index < nums.size(); ++index) {
            // Skip duplicates
            if (index > i && nums[index] == nums[index - 1])
                continue;

            current.push_back(nums[index]);                  // Include
            backtrack(index + 1, nums, current, result);     // Recurse
            current.pop_back();                              // Backtrack
        }
    }
};
