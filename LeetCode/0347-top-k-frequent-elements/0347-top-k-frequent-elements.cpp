class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), compare);

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(vec[i].first);
        }

        return result;
    }
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};