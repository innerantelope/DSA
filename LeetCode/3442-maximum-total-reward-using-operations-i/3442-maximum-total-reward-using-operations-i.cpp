class Solution {
public:
    int solve(vector<int>& rewardValues,int i, int cur,vector<vector<int>>& dp) {
        if (i == rewardValues.size())
            return 0;
        if (dp[i][cur] != -1)
            return dp[i][cur];
        int skip = solve(rewardValues, i + 1, cur, dp);
        int take = 0;
        if (rewardValues[i] > cur) {
            take = rewardValues[i] +solve(rewardValues,i + 1,cur + rewardValues[i],dp);
        }
        return dp[i][cur] = max(take, skip);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        vector<vector<int>> dp(rewardValues.size(),vector<int>(4001, -1)
        );
        return solve(rewardValues, 0, 0, dp);
    }
};