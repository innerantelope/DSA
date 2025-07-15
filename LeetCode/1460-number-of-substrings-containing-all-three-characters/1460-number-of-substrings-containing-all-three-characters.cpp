class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int n=s.length();
        int count[3] = {0};
        int l=0;
        for (int r = 0; r < s.length(); r++) {
            count[s[r] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += (n - r);
                count[s[l]-'a']--;
                l++;
            }
        }
        return res;
    }
};