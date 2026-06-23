class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        //{time,r,c}
        int m=moveTime.size();
        int n=moveTime[0].size();
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        dis[0][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        pq.push({0,0,0});
        vector<vector<int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
        while(!pq.empty()){
            auto[t,r,c]=pq.top();
            pq.pop();
            if(t>dis[r][c]) continue;
            for(int k=0;k<4;k++){
                int nr=r+dir[k][0];
                int nc=c+dir[k][1];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int nt=max(t,moveTime[nr][nc])+1;
                    if(nt<dis[nr][nc]){
                        dis[nr][nc]=nt;
                        pq.push({nt,nr,nc});
                    }
                }

            }


        }

        return dis[m-1][n-1];



        
    }
};