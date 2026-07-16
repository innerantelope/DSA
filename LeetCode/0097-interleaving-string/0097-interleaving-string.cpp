class Solution {
public:
    int t[101][101][201];
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        memset(t,-1,sizeof(t));
        return solve(s1,s2,s3,0,0,0);
    }
    bool solve(string &s1, string &s2, string &s3,int i,int j,int k){
        
        if(i==s1.size()&& j==s2.size() && k==s3.size()) return true;
        if(t[i][j][k]!=-1) return t[i][j][k];
        if(i<s1.size() &&s1[i]==s3[k]) if(solve(s1,s2,s3,i+1,j,k+1)) return t[i][j][k]= true;
        if(j<s2.size() &&s2[j]==s3[k]) if(solve(s1,s2,s3,i,j+1,k+1)) return t[i][j][k]= true;
        return t[i][j][k]=false;


    }
};