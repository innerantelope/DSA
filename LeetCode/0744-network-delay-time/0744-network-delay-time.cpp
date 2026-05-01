class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans(n+1,INT_MAX);
        ans[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto[d,node]=pq.top();
            pq.pop();
            for(auto &s:adj[node]){
                int x=s.first;
                int weight=s.second;
                if(d+weight<ans[x]){
                    ans[x]=d+weight;
                    pq.push({d+weight,x});
                }

            }

        }

        int maxi = 0;

     for(int i = 1; i <= n; i++) {
    if(ans[i] == INT_MAX) return -1;
    maxi = max(maxi, ans[i]);
    }

      return maxi;

        
    }
};