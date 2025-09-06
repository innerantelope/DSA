class Solution {
public:
    long long prefixSteps(long long x) {
        if (x <= 0) return 0;
        long long steps = 0, low = 1, high = 3, level = 1;
        while (low <= x) {
            long long r = min(high, x);
            steps += (r - low + 1) * level;
            low *= 4;
            high = high * 4 + 3;
            level++;
        }
        return steps;
    }

    long long rangeSteps(long long l, long long r) {
        return prefixSteps(r) - prefixSteps(l - 1);
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long totalAns = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = rangeSteps(l, r);
            totalAns += (totalSteps + 1) / 2;
        }
        return totalAns;
    }
};
