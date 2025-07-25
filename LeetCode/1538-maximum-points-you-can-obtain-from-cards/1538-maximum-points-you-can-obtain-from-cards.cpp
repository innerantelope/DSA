class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum= 0;   
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int maxSum=sum;
        for (int i = 0; i <k; i++) {
          sum=sum-cardPoints[k-1-i]+cardPoints[n-1-i];
          maxSum=max(maxSum,sum);
        }

        return maxSum;
    }
};
