class Solution {
public:
    bool dfs(int i,vector<vector<int>>&adj,vector<int>&states,vector<int>&topo){
        states[i]=1;
        for(auto &s:adj[i]){
            if(states[s]==0){
                if(dfs(s,adj,states,topo)) return true;
            }
            else if(states[s]==1) return true;
        }
        states[i]=2;
        topo.push_back(i);
        return false;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        vector<int>states(numCourses,0);
        vector<int>topo;
        for(int i=0;i<numCourses;i++){
            if(states[i]==0){
                if(dfs(i,adj,states,topo)) return {};
            }
        }
        reverse(topo.begin(),topo.end());
        return topo;
        
    }
};