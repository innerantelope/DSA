class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        int start=0;
        int maxl=0;
        if(len<2) return s;
        for(int i=0;i<len;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<len && s[l]==s[r]){
                if(r-l+1>maxl){
                    start=l;
                    maxl=r-l+1;
                }
                l--;
                r++;
            }
            l=i; r=i+1;
            while(l>=0 && r<len && s[l]==s[r]){
               if(r-l+1>maxl){
                    start=l;
                    maxl=r-l+1;
                }
                l--;
                r++;
            }

        }

        return s.substr(start,maxl);

        
    }
};