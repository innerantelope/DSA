class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            int col=0;
            for(int j=1;j<n;j++){
                if(matrix[i][j]<matrix[i][col]){
                    col=j;
                }
            }
            bool chk=true;
            for(int k=0;k<m;k++){
                if(matrix[k][col]>matrix[i][col]){
                    chk=false;
                    break;
                }
            }
            if(chk) return {matrix[i][col]};
        }
        return {};
        
    }
};