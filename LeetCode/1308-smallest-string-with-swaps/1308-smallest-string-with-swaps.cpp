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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        DSU dsu(n);
        for(auto &i:pairs){
            dsu.unions(i[0],i[1]);
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            int parent = dsu.find(i);
            mp[parent].push_back(i);
        }
        string res=s;
        for(auto &it:mp){
            vector<int>&idx=it.second;
            string chars="";
            for(int i:idx) chars+=s[i];
            sort(chars.begin(),chars.end());
            for(int i=0;i<idx.size();i++){
                res[idx[i]]=chars[i];
            }

        }

        return res;

        
    }
};