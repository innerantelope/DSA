class Solution {
public:
    string getHappyString(int n, int k) {
        int t=3*pow(2,n-1);
        if(k>t) return "";
        string res="";
        char prev='.';
        for(int i=0;i<n;i++){
            for(char ch:{'a','b','c'}){
                if(ch==prev) continue;
                int c=pow(2,n-i-1);
                if(k>c){
                    k-=c;
                }
                else{
                    res.push_back(ch);
                    prev=ch;
                    break;
                }
            }
        }

        return res;
        
    }
};