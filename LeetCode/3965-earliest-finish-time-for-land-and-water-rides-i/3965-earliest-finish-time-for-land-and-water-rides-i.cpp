class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinish = INT_MAX;
        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                int landEnd = landStartTime[i] + landDuration[i];
                int waterStart = max(landEnd, waterStartTime[j]);
                int total1 = waterStart + waterDuration[j];
                int waterEnd = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterEnd, landStartTime[i]);
                int total2 = landStart + landDuration[i];
                minFinish = min({minFinish, total1, total2});
            }
        }

        return minFinish;
    }
};
