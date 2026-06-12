class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int, vector<int>>> pq;
        for(auto &i:points){
            int x=i[0];
            int y=i[1];
            int dist=(x*x)+(y*y);
            pq.push({dist,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()!=0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};