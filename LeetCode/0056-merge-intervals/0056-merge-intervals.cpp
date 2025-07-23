class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        int end_time = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            auto& current = intervals[i];
            auto& last = merged.back();

            if (current[0] <= last[1]) {
                last[1] = max(last[1], current[1]);
            } else {
                merged.push_back(current);
            }
        }

        return merged;
    }
};
