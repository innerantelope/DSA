class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int i,vector<int>&visited,vector<int>&inr){
        visited[i]=true;
        inr[i]=true;
        for(auto&e:graph[i]){
            if(!visited[e] && dfs(graph,e,visited,inr)) return true;
            else if(inr[e]==true) return true;
        }
        inr[i]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>visited(V,false);
        vector<int>inr(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(graph,i,visited,inr);
            }
        }
        vector<int>safenodes;
        for(int i=0;i<V;i++){
            if(!inr[i]) safenodes.push_back(i);
        }

        return safenodes;

                
    }
};