class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        string res="";
        while(n>0){
            int temp=n%10;
            if(temp!=0) {
             res+=(temp+'0');
             sum+=temp;
            }
            n=n/10; 
        }
        if(res.empty()) return 0;
        reverse(res.begin(),res.end());
        long long ans=stoll(res);
        return ans*sum;
        
        
    }
};