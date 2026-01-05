class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int neg = 0;
        long long sum =0;
        int x = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                int val = matrix[i][j];
                if(val<0) neg++;
               x= min(x,abs(val));

                
            }
        }
        if(neg%2==0) return sum;
        else {
           return sum-2LL*x;
        }
        
    }
};