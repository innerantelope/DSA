class Solution {
public:
    struct Node {
        int nxt[26];
        int len;
        int idx;

        Node() {
            memset(nxt, -1, sizeof(nxt));
            len = INT_MAX;
            idx = -1;
        }
    };

    vector<Node> t;

    void upd(int node, int l, int i) {
        if (l < t[node].len) {
            t[node].len = l;
            t[node].idx = i;
        }
    }

    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        t.emplace_back();

        for (int i = 0; i < wc.size(); i++) {
            int cur = 0;
            int l = wc[i].size();

            upd(cur, l, i);

            for (int j = l - 1; j >= 0; j--) {
                int c = wc[i][j] - 'a';

                if (t[cur].nxt[c] == -1) {
                    t[cur].nxt[c] = t.size();
                    t.emplace_back();
                }

                cur = t[cur].nxt[c];
                upd(cur, l, i);
            }
        }

        vector<int> ans;

        for (auto &s : wq) {
            int cur = 0;

            for (int j = s.size() - 1; j >= 0; j--) {
                int c = s[j] - 'a';

                if (t[cur].nxt[c] == -1)
                    break;

                cur = t[cur].nxt[c];
            }

            ans.push_back(t[cur].idx);
        }

        return ans;
    }
};