class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dirs={{0,-1},{0,1},{1,0},{-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        auto issafe=[&](int x,int y){
            return (x>=0 && x<m && y<n && y>=0);
        };
        result[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto[r,c]=pq.top();
            int x=c.first;
            int y=c.second;
            pq.pop();
           for(auto &d:dirs){
            int x_=x+d[0];
            int y_=y+d[1];
            if(issafe(x_,y_)){
                int absdiff=abs(heights[x][y]-heights[x_][y_]);
                int max_diff=max(absdiff,r);
                if(result[x_][y_]>max_diff){
                    result[x_][y_]=max_diff;
                    pq.push({max_diff,{x_,y_}});
                }

            }
           }

            
        }
        return result[m-1][n-1];
        
    }
};