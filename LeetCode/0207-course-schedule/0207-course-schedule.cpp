class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //detect cycle in a graph
        //0->1->0;
        //0->1
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;
        int count=0;
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto &p:adj[node]){
                indegree[p]--;
                if(indegree[p]==0){
                    q.push(p);
                }
            }

        }
        //0->1;
        //0->1->0;
        return count==numCourses;
    }
};