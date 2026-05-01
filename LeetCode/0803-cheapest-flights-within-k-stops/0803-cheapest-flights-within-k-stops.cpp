class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        int steps=0;
        while(!q.empty() && steps<=k){
            int size=q.size();
            while(size--){
                int u=q.front().first;
                int d=q.front().second;
                q.pop();
                for( auto&it:adj[u]){
                    int x=it.first;
                    int w=it.second;
                    if(d+w<dist[x]){
                        dist[x]=d+w;
                        q.push({x,d+w});
                    }
                }
            }
            steps++;

        }

        return dist[dst]==INT_MAX?-1:dist[dst];



        
    }
};