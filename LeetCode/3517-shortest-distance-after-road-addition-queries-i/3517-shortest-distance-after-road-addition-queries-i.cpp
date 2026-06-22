class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++) adj[i].push_back(i+1);
        vector<int>ans;
        for(auto &q:queries){
            int u=q[0];
            int v=q[1];
            adj[u].push_back(v);
            vector<int>dist(n,-1);
            queue<int>qu;
            dist[0]=0;
            qu.push({0});
            while(!qu.empty()){
                int node=qu.front();
                qu.pop();
                for(int nei:adj[node]){
                    if(dist[nei]==-1){
                        dist[nei]=dist[node]+1;
                        qu.push(nei);
                    }
                }
            }
            ans.push_back(dist[n-1]);
        }

        return ans;
        
    }
};