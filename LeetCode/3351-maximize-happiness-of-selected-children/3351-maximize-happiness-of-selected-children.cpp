class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        sort(happiness.rbegin(), happiness.rend());

        vector<long long> prefix_sum(k);
        prefix_sum[0] = happiness[0];

        for (int i = 1; i < k; i++) {
            long long add = happiness[i] - i;
            if (add < 0) add = 0;
            prefix_sum[i] = prefix_sum[i - 1] + add;
        }

        return prefix_sum[k - 1];
    }
};
