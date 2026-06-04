class Solution {
public:
    int totalWaviness(int num1, int num2) {
        long long total=0;
        if(num1<100 && num2<100) return 0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            for(int i=1;i<s.size()-1;i++){
                if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i]<s[i+1])) total++;
            }
            
        }
        
        return total;
    }
};