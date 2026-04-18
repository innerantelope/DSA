class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);
        int i2,i3,i5;
        i2=i3=i5=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int i2n=dp[i2]*2;
            int i3n=dp[i3]*3;
            int i5n=dp[i5]*5;
            int mini=min({i2n,i3n,i5n});
            dp[i]=mini;
            if(mini==i2n) i2++;
            if(mini==i3n) i3++;
            if(mini==i5n) i5++;


        }
        return dp[n];
        
    }
};