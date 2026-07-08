class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);

        }
        vector<pair<int,int>>ans;
        for(auto &it:mp){
            ans.push_back({it.second.front(),it.second.back()});
        }
        sort(ans.begin(),ans.end());
        vector<int>q;
        int p=ans[0].first;
        int e=ans[0].second;
        for(int i=1;i<ans.size();i++){
            if(ans[i].first<=e){
                e=max(e,ans[i].second);
            }
            else{
                q.push_back(e-p+1);
                p=ans[i].first;
                e=ans[i].second;
            }
        }
        q.push_back(e-p+1);

        return q;
    }
};