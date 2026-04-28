class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans.push_back(grid[i][j]);
            }
        }
       int base = ans[0];
       for (int val : ans) {
        if ((val - base) % x != 0) {
           return -1;
        }
    }
        sort(ans.begin(),ans.end());
        int median=ans[ans.size()/2];
        int op=0;
        for(int val: ans){
            op+=abs(val-median)/x;
        }
        return op;
        
    }
};