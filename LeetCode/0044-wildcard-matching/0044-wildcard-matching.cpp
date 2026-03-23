class Solution {
public:
    bool pm(string &s,string&p,int n,int m,vector<vector<int>>&dp){
        if (m == 0) return (n == 0);
        if(n==0){
            for(int i=0;i<m;i++){
                if(p[i]!='*')return dp[n][m]= false;
            }
             return dp[n][m]=true;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==p[m-1] || p[m-1]=='?'){
                return dp[n][m]=pm(s,p,n-1,m-1,dp);
        }
        if(p[m-1]=='*'){
            return dp[n][m]=pm(s,p,n-1,m,dp)||pm(s,p,n,m-1,dp);
        }
        return dp[n][m]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return pm(s,p,n,m,dp);
        
    }
};