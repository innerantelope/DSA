class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int magic_sq = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (grid[i + 1][j + 1] != 5) continue;

                set<int> st;

                int r1 = 0, r2 = 0, r3 = 0;
                int c1 = 0, c2 = 0, c3 = 0;
                int d1 = 0, d2 = 0;

                bool ok = true;

                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        int val = grid[x][y];

                        if (val < 1 || val > 9 || st.count(val)) {
                            ok = false;
                            break;
                        }
                        st.insert(val);

                        if (x == i) r1 += val;
                        else if (x == i + 1) r2 += val;
                        else r3 += val;

                        if (y == j) c1 += val;
                        else if (y == j + 1) c2 += val;
                        else c3 += val;

                        if (x - i == y - j) d1 += val;
                        if (x - i + y - j == 2) d2 += val;
                    }
                    if (!ok) break;
                }

                if (!ok) continue;

                if (r1 == r2 && r2 == r3 &&
                    r1 == c1 && c1 == c2 && c2 == c3 &&
                    r1 == d1 && d1 == d2) {
                    magic_sq++;
                }
            }
        }

        return magic_sq;
    }
};
