class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int x : answers) mp[x]++;
        int ans = 0;
        for(auto &it : mp) {
            int x = it.first;
            int freq = it.second;
            int grs= x + 1;
            int gr = (freq + grs - 1) / grs;
            ans += gr*grs;
        }

        return ans;
    }
};