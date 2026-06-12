class cmp{
    public:
     bool operator()(pair<int,string>& a, pair<int,string>& b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        unordered_map<string,int> freq;
        for(string &s : words) freq[s]++;
        for(auto &p:freq){
            pq.push({p.second,p.first});
        }
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};