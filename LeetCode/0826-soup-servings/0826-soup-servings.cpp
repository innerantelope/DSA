class Solution {
public:
    double memo[205][205];

    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (memo[a][b] >= 0) return memo[a][b];

        double res = 0.0;
        res += 0.25 * dfs(a - 4, b);
        res += 0.25 * dfs(a - 3, b - 1);
        res += 0.25 * dfs(a - 2, b - 2);
        res += 0.25 * dfs(a - 1, b - 3);

        return memo[a][b] = res;
    }

    double soupServings(int n) {
        if (n == 0) return 0.5;
        int N = (n + 24) / 25; // normalize to 25 mL units
        if (N >= 200) return 1.0; // threshold optimization

        for (int i = 0; i <= 200; ++i)
            for (int j = 0; j <= 200; ++j)
                memo[i][j] = -1.0;

        return dfs(N, N);
    }
};
