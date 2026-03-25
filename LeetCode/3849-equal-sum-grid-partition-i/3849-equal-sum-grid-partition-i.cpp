class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        long long sum=0;
        for(int i=0;i<m;i++){
            for(int x:grid[i]) sum+=x;
        }
        long long comp=0;
        for(int i=0;i<m-1;i++){
            for(int x:grid[i]){
                comp+=x;
            }
            if(2*comp==sum) return true; 
        }
        long long comps=0;
        for(int j=0;j<n-1;j++){
            for(int i=0;i<m;i++){
                comps+=grid[i][j];
            }
            if(2*comps==sum) return true; 
        }
        return false;
        
    }
};