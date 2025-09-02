class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int Ax = points[i][0], Ay = points[i][1];
                int Bx = points[j][0], By = points[j][1];

                // A must be upper-left (non-strict allowed)
                if (Ax <= Bx && Ay >= By && (Ax < Bx || Ay > By)) {
                    bool valid = true;

                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int Cx = points[k][0], Cy = points[k][1];

                        if (min(Ax, Bx) <= Cx && Cx <= max(Ax, Bx) &&
                            min(Ay, By) <= Cy && Cy <= max(Ay, By)) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) count++;
                }
            }
        }
        return count;
    }
};
