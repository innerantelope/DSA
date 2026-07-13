class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>&vis, int i,int j){
        vis[i][j]=1;
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        for(int k=0;k<4;k++){
            int dr=i+dir[k][0];
            int dc=j+dir[k][1];
            if(dr>=0 && dr<m && dc>=0 && dc<n && !vis[dr][dc] && board[dr][dc]=='O'){
                dfs(board,vis,dr,dc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(board,vis,0,j);
            }
        }
        for(int j=0;j<n;j++){
            if(board[m-1][j]=='O' && !vis[m-1][j]){
                dfs(board,vis,m-1,j);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(board,vis,i,0);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O' && !vis[i][n-1]){
                dfs(board,vis,i,n-1);
            }
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }

        }

        
    }
};