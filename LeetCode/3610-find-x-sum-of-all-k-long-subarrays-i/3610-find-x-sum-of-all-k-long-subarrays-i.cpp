class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            vector<pair<int, int>> vec(freq.begin(),freq.end());
        
            sort(vec.begin(), vec.end(), [&](auto& a, auto& b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second>b.second;
            });

            int windowSum = 0;
            for (int j = 0; j <x && j<freq.size(); j++) {
                windowSum += vec[j].first * vec[j].second;
            }

            result.push_back(windowSum);
        }

        return result;
    }
};
