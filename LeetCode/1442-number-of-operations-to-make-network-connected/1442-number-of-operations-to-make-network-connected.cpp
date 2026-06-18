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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int x=connections.size();
        if(x< n-1) return -1;
        DSU dsu(x);
        int ans=0;
        for(auto &edge:connections){
        int u=edge[0];
        int v=edge[1];
        dsu.unions(u,v);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(dsu.findparent(i)==i) components++;
        }

        return components-1;
        
    }
};