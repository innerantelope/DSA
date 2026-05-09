class Solution {
public:
    typedef pair<int,int>P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<bool>mst(points.size(),false);
        int cost=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto[ccost,node]=pq.top();
            pq.pop();
            if(mst[node]) continue;
            cost+=ccost;
            mst[node]=true;
            for(int i=0;i<points.size();i++){
                if(!mst[i]){
                    int x1=points[node][0];
                    int x2=points[i][0];
                    int y1=points[node][1];
                    int y2=points[i][1];
                    int dist=abs(x2-x1)+abs(y2-y1);
                    pq.push({dist,i});

                }

            }
            


        }

        return cost;




        
    }
};