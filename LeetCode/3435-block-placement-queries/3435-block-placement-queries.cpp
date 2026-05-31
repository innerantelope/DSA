class Solution {
public:
    struct SegTree {
        int n;
        vector<int> st;

        SegTree(int n) : n(n), st(4 * n + 4, 0) {}

        void upd(int p, int val, int i, int l, int r) {
            if (l == r) {
                st[i] = val;
                return;
            }

            int m = (l + r) >> 1;

            if (p <= m) upd(p, val, i << 1, l, m);
            else upd(p, val, i << 1 | 1, m + 1, r);

            st[i] = max(st[i << 1], st[i << 1 | 1]);
        }

        void upd(int p, int val) {
            upd(p, val, 1, 0, n);
        }

        int qry(int L, int R, int i, int l, int r) {
            if (L > r || R < l) return 0;
            if (L <= l && r <= R) return st[i];

            int m = (l + r) >> 1;

            return max(
                qry(L, R, i << 1, l, m),
                qry(L, R, i << 1 | 1, m + 1, r)
            );
        }

        int qry(int l, int r) {
            if (l > r) return 0;
            return qry(l, r, 1, 0, n);
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 0;

        for (auto &q : queries)
            mx = max(mx, q[1]);

        set<int> s;
        s.insert(0);
        s.insert(mx + 1);

        for (auto &q : queries)
            if (q[0] == 1)
                s.insert(q[1]);

        SegTree seg(mx + 1);

        auto it = s.begin();
        auto prv = it++;

        while (it != s.end()) {
            seg.upd(*it, *it - *prv);
            prv = it++;
        }

        vector<bool> ans;

        for (int i = queries.size() - 1; i >= 0; --i) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = s.upper_bound(x);
                int r = *prev(it);

                int best = seg.qry(0, r);

                ans.push_back(max(best, x - r) >= sz);
            } else {
                int x = q[1];

                auto it = s.find(x);
                auto l = prev(it);
                auto r = next(it);

                seg.upd(*r, *r - *l);
                s.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};