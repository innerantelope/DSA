class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int ans=1;
        int count=9;
        int av=9;
        for(int i=1;i<=n;i++){
            if(i==1){
                ans+=count;
            }
            else{
                count*=av;
                ans+=count;
                av--;
            }
        }
        return ans;
        
    }
};