class Solution {
public:
    int minFlips(string s) {
        int n= s.size();
        string z= s+s;
        string alt1="",alt2="";
        for(int i=0;i<2*n;i++){
            alt1+=(i%2?'1':'0');
            alt2+=(i%2?'0':'1');
        }
        int diff1=0,diff2=0;
        int ans=INT_MAX;
        int l=0;

        for(int i=0;i<2*n;i++){
            if(z[i]!=alt1[i]) diff1++;
            if(z[i]!=alt2[i]) diff2++;
            if(i-l+1>n){
            if(z[l]!=alt1[l]) diff1--;
            if(z[l]!=alt2[l]) diff2--;
            l++;
            }

            if(i-l+1==n){
                ans=min(ans,min(diff1,diff2));
            }

        }

        return ans;
        
    }
};