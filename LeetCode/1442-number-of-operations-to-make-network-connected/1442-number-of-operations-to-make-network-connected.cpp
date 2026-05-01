class DSU{
public:
  vector<int>parent;
  vector<int>rank;
   DSU(int n){
    parent.resize(n+1);
    rank.resize(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

   }
   int find(int x){
      if(x==parent[x]) return x;
      return parent[x]=find(parent[x]);
   }
   void unions(int x,int y){
      int x_parent=find(x);
      int y_parent=find(y);
      if(x_parent==y_parent) return;
      if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
      else if(rank[y_parent]>rank[x_parent]) parent[x_parent]=y_parent;
      else {
     parent[y_parent]=x_parent;
      rank[x_parent]++;
      }

   }


};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        if(connections.size()<n-1) return -1;
        for(auto &conn:connections){
            dsu.unions(conn[0],conn[1]);
        }
        int op=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i) op++;
        }

        return op-1;

        
    }
};