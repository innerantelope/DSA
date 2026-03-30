class Solution {
public:
    int minDeletions(string s) {
        int cnt=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<int>ans;
        for(auto &i:mp){
            ans.push_back(i.second);
        }
        sort(ans.rbegin(),ans.rend());
        for(int i=1;i<ans.size();i++){
            if(ans[i]>=ans[i-1]){
                int fix=max(0,ans[i-1]-1);
                cnt+=ans[i]-fix;
                ans[i]=fix;
            }

        }
        return cnt;


        


        
    }
};