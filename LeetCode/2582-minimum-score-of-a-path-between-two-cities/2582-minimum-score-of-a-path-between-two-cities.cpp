class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>>&adj, vector<int>&vis,int &ans){
        vis[node]=1;
        for(auto &neig:adj[node]){
            ans=min(ans,neig.second);
            if(!vis[neig.first]) dfs(neig.first,adj,vis,ans);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>vis(n+1,0);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        int ans=INT_MAX;
        dfs(1,adj,vis,ans);
        return ans;



    }
};