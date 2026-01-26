class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string ans = "";
        for (char c : s) {
            
            while (!ans.empty() && ans.back() > c && count[ans.back() - 'a'] > 1) {
                count[ans.back() - 'a']--; 
                ans.pop_back();
            }
            ans += c;
        }
        while (!ans.empty() && count[ans.back() - 'a'] > 1) {
            count[ans.back() - 'a']--;
            ans.pop_back();
        }

        return ans;
    }
};