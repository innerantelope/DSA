class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sumfe = 0;
        int sumfb = 0;

        for (int i = 0; i < k; i++) {
            sumfb += cardPoints[i];
        }

        int maxSum = sumfb;

        for (int i = 1; i <= k; i++) {
            sumfb -= cardPoints[k - i];             
            sumfe += cardPoints[n - i];            
            maxSum = max(maxSum, sumfb + sumfe);
        }

        return maxSum;
    }
};
