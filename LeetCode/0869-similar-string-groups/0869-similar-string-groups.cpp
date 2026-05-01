class DSU{
public:
  vector<int>parent;
  vector<int>rank;
   DSU(int n){
    parent.resize(n);
    rank.resize(n,0);
    for(int i=0;i<n;i++){
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
    bool issimilar(string &a,string &b){
        int diff=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) diff++;
            if(diff>2){
                return false;
                continue;
            }
        }
        return true;

    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(issimilar(strs[i],strs[j])){
                    dsu.unions(i,j);
                }
            }
        }
        int grp=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i) grp++;
        }

        return grp;

        
    }
};