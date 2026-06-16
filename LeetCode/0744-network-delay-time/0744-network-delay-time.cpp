class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &e:times){
           adj[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans(n+1,INT_MAX);
        ans[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto[r,c]=pq.top();
            pq.pop();
            for(auto &neig:adj[c]){
                if(neig.second+r<ans[neig.first]){
                    ans[neig.first]=neig.second+r;
                    pq.push({r+neig.second,neig.first});
                }
            }

        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(ans[i]==INT_MAX)return -1;
            maxi=max(maxi,ans[i]);
        }

        return maxi;

    }
};