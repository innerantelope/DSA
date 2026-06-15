class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,int>indegree;
        int n=recipes.size();
        for(int i=0;i<n;i++){
            indegree[recipes[i]]=ingredients[i].size();
            for(auto &s:ingredients[i]){
                adj[s].push_back(recipes[i]);
            }
        }
        vector<string>ans;
        queue<string>q;
        for(auto &s:supplies){
            q.push(s);
        }
        while(!q.empty()){
            string item=q.front();
            q.pop();
            for(auto &neig:adj[item]){
                indegree[neig]--;
                if(indegree[neig]==0){
                    ans.push_back(neig);
                    q.push(neig);
                }

            }

        }
        return ans;
        
    }
};