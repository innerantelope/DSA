class Solution {
public:
    int minimumDeletions(string s) {
        int bcount=0;
        int del=0;
        for(char c:s){
            if(c=='b'){
                bcount++;
            }
            else{
                del = min(del+1,bcount);
            }
        }
        return del;
        
    }
};