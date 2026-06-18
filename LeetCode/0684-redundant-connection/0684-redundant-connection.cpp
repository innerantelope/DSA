class DSU{
    public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findparent(parent[node]);
    }
    void unions(int u,int v){
        int x=findparent(u);
        int y=findparent(v);
        if(x!=y){
            parent[x]=y;
        }

    }

 };
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        if(dsu.findparent(u)==dsu.findparent(v)) return edge;
        dsu.unions(u,v);
        }

        return {};

        
    }
};