class Solution {
public:
    bool dfs(int u,int v,unordered_map<int,vector<int>>&adj,vector<vector<int>>&edges,vector<int>&visited){
        visited[u]=true;
        if(u==v) return true;
        for(auto &neig:adj[u]){
            if(visited[neig]) continue;
            if(dfs(neig,v,adj,edges,visited)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            vector<int>visited(n+1,false);
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(u,v,adj,edges,visited)) 
               return edges[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};

        
    }
};