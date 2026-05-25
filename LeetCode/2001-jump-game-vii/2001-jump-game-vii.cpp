class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n =s.size();
        vector<int>r(n,false);
        r[0]=true;
        int count=0;
        for(int i=1;i<n;i++){
            if(i-minJump>=0 && r[i-minJump]){
                count++;
            }
            if(i-maxJump-1>=0 && r[i-maxJump-1]){
                count--;
            }
            if(count>0 && s[i]=='0'){
                r[i]=true;
            }
        }
        return r[n-1];
        
    }
};