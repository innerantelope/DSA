class Solution {
public:
    bool solve(int i,int j,string&s){
        if(i>=j) return true;
        if(s[i]==s[j]) return solve(i+1,j-1,s);
        return false;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxl=1;
        int p=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(solve(i,j,s)){
                    if(j-i+1>maxl){
                        maxl=j-i+1;
                        p=i;
                    }

                }
            }
        }
        return s.substr(p,maxl);
        
    }
};