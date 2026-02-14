class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;
        
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++){
            vector<long long> temp(target + 1, 0);
            
            for(int sum = 1; sum <= target; sum++){
                for(int dice = 1; dice <= k; dice++){
                    if(sum - dice >= 0){
                        temp[sum] = (temp[sum] + dp[sum - dice]) % MOD;
                    }
                }
            }
            
            dp = temp;
        }
        
        return dp[target];
    }
};
