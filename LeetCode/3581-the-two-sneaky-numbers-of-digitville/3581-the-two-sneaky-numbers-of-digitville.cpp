class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        vector<int> res;
        for (auto& j : mp) {
            if (j.second > 1) {
                res.push_back(j.first);
            }
        }
        return res;
    }
};