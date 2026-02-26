class Solution {
public:
bool isPowerOfTwo(string s) {
    int countOnes = 0;
    for(char c : s) {
        if(c == '1') {
            countOnes++;
            if(countOnes > 1) return false;
        }
    }
    return countOnes == 1;
}
int numSteps(string s) {
       int n = s.size();
       int count = 0;
       while(!isPowerOfTwo(s)){
          if(s.back()=='1'){
            int i = s.size()-1;
            while(i>=0 && s[i]=='1'){
                s[i]='0';
                i--;
            }
            if(i>=0){
                s[i]='1';
            }
            else s= "1"+s;
            count++;
          }
          else{
            s.pop_back();
            count++;
          }

       }
       count += (s.size() - 1);
       return count;
    }
};