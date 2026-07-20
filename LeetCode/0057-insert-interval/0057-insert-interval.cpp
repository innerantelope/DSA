class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>>results;
            bool chk=false;
            for(int i=0;i<intervals.size();i++){
                if(!chk && newInterval[0]<intervals[i][0]){
                    results.push_back(newInterval);
                    chk=true;
                }
                results.push_back(intervals[i]);
            }
            if(!chk) results.push_back(newInterval);
            vector<vector<int>>ans;
            ans.push_back(results[0]);
            for (int i = 1; i < results.size(); i++) {
            if (results[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], results[i][1]);
            } else {
                ans.push_back(results[i]);
            }
        }
       return ans;
    }
};