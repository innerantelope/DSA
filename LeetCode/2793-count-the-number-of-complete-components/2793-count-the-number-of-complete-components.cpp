class Solution {
public:
    void dfs(int n,vector<vector<int>>&adj,vector<bool>&vis,int&nodes,int&edges){
        vis[n]=true;
        nodes++;
        edges+=adj[n].size();
        for(auto &neig:adj[n]){
            if(!vis[neig]){
                dfs(neig,adj,vis,nodes,edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int n=0,ec=0;
                dfs(i,adj,vis,n,ec);
                ec/=2;
                long long exp=1LL*n*(n-1)/2;
                if(ec==exp) ans++;
            }

        }
        return ans;
        
    }
};