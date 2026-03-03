class Solution {
public:
    string ans(int n){
        if(n == 1) return "0";
        string j = "0";
        for(int i = 2; i <= n; i++){
            string prev = j;
            string rev = prev;
            reverse(rev.begin(), rev.end());
            for(int k = 0; k < rev.size(); k++){
                if(rev[k] == '0') rev[k] = '1';
                else rev[k] = '0';
            }
            
            j = prev + "1" + rev;
        }
        
        return j;
    }

    char findKthBit(int n, int k) {
        string w = ans(n);
        return w[k-1]; 
    }
};