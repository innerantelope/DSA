class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        long long ans = 0;
        for (int x : deliciousness) {
            for (int sum = 1; sum <= (1 << 21); sum <<= 1) {
                int need = sum - x;
                if (freq.count(need)) {
                    ans = (ans + freq[need]) % MOD;
                }
            }
            freq[x]++;
        }

        return ans;
    }
};