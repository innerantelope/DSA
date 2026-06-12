class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        vector<int>freq(26,0);
        for(char p:s){
            freq[p-'a']++;
        }
        for(char c = 'a'; c <= 'z'; c++){
            if(freq[c - 'a'] > 0){
                pq.push({freq[c - 'a'], c});
            }
        }
        string ans="";
        pair<int,char> prev = {0, '#'};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            ans+=curr.second;
            curr.first--;
            if(prev.first>0) pq.push(prev);
            prev=curr;
        }
        if(ans.size()!=s.size()) return "";
        return ans;
    }
};