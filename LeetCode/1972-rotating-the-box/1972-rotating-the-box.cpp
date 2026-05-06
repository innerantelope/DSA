class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        vector<vector<char>>ans(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][m-i-1]=boxGrid[i][j];
            }
        }
       
        for(int j=0;j<m;j++){
            int blank=n-1;
            for(int i=n-1;i>=0;i--){
                if(ans[i][j]=='*') blank=i-1;
                else if(ans[i][j]=='#'){
                 swap(ans[i][j],ans[blank][j]);
                 blank--;
                }   
            
        }   }   

        return ans;
    
    }
};