class Solution {
public:
    int minSteps(int n) {
        //A->Copy All op use
        //A->AA
        //Again paste operation use A->AAA for n=3
        //dp[i] will represent the min op required to get the char exactly i times
        vector<int>dp(n+1,INT_MAX);
        dp[1]=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i%j==0){
                    dp[i]=min(dp[i],dp[j]+i/j);
                }
            }
        }

        return dp[n];

    }
};