class Solution {
public:
    long long flowerGame(int n, int m) {
        long long pairs =1LL*n * m;
        if (pairs == 1)
            return 0;
        else
            return pairs / 2;
    }
};
