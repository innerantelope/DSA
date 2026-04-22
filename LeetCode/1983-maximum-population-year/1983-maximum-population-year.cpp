class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101, 0);
        
        for (auto &log : logs) {
            diff[log[0] - 1950]++;   
            diff[log[1] - 1950]--;  
        }
        int maxPop = 0, curr = 0, year = 1950;
        
        for (int i = 0; i < 101; i++) {
            curr += diff[i];
            if (curr > maxPop) {
                maxPop = curr;
                year = 1950 + i;
            }
        }
        
        return year;
    }
};