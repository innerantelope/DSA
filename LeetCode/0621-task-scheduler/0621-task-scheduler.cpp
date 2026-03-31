class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char i:tasks){
            freq[i-'A']++;
        }
       int y= *max_element(freq.begin(),freq.end());
       int countmax=0;
       for(int s:freq){
        if(s==y) countmax++;
       }
       int ans=(y-1)*(n+1)+countmax;
       return max((int)tasks.size(),ans);

        
    }
};