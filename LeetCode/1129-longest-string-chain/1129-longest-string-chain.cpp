class Solution {
public:
    bool ispre(string &a,string &b){
        if(a.size()+1!=b.size()) return false;
        int i=0;
        int j=0;
        int chk=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else {
                if(chk) return false;
                chk=1;
                j++;
            }
        }
        return true;


    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        vector<int>dp(words.size(),1);
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(ispre(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }

        return *max_element(dp.begin(),dp.end());

        
    }
};