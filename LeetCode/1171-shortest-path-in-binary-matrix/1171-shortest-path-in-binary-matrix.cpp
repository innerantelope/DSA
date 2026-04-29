class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1; 
        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};
        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                if(x == n-1 && y == n-1) return dist;
                for(int k=0;k<8;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                        grid[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};