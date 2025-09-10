class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        //pairing
        vector<unordered_set<int>> langSet(m + 1);
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) {
                langSet[i + 1].insert(l);
            }
        }

        //bad pairs
        vector<pair<int,int>> badPairs;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canTalk = false;
            for (int l : langSet[u]) {
                if (langSet[v].count(l)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                badPairs.push_back({u, v});
            }
        }

        if (badPairs.empty()) return 0; //fine

        int ans = INT_MAX;

        for (int L = 1; L <= n; L++) {
            unordered_set<int> needTeach;

            for (auto &p : badPairs) {
                int u = p.first, v = p.second;

                if (!langSet[u].count(L)) needTeach.insert(u);
                if (!langSet[v].count(L)) needTeach.insert(v);
            }
            ans = min(ans, (int)needTeach.size());
        }

        return ans;
    }
};
