class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int countx1=0,countx2=0,county1=0,county2=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x' && s2[i]=='y') countx1++;
            else if(s1[i]=='y' && s2[i]=='x') county1++;
        }
        if((countx1 + county1) % 2 != 0) return -1;

        return (countx1/2) + (county1/2) + (countx1%2)*2;
    }
};