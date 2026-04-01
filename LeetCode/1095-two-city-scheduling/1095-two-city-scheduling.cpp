class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        
        vector<pair<int,int>> diff;
        
        for(int i = 0; i < n; i++){
            diff.push_back({costs[i][0] - costs[i][1], i});
        }

        sort(diff.begin(), diff.end());

        int ans = 0;
        for(int i = 0; i < n/2; i++){
            int idx = diff[i].second;
            ans += costs[idx][0];
        }

        for(int i = n/2; i < n; i++){
            int idx = diff[i].second;
            ans += costs[idx][1];
        }

        return ans;
    }
};