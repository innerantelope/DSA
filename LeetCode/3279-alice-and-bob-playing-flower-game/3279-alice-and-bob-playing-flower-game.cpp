class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddA = (n + 1) / 2;
        long long evenA = n / 2;
        long long oddB = (m + 1) / 2;
        long long evenB = m / 2;

        return oddA * evenB + evenA * oddB;
    }
};
