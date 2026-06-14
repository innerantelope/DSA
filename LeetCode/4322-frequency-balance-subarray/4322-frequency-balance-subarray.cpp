class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> cnt;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                if (freq[x]) {
                    cnt[freq[x]]--;
                    if (cnt[freq[x]] == 0)
                        cnt.erase(freq[x]);
                }
                freq[x]++;
                cnt[freq[x]]++;
                if (freq.size() == 1) {
                    ans = max(ans, j - i + 1);
                }
                else if (cnt.size() == 2) {
                    auto it = cnt.begin();
                    int a = it->first;
                    it++;
                    int b = it->first;
                    if (a > b) swap(a, b);
                    if (b == 2 * a)
                        ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};