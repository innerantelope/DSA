class Solution {
public:
    vector<vector<string>> result; // Declare result globally

    vector<vector<string>> partition(string s) {
        vector<string> current;
        backtrack(0, current, s);
        return result;
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

    void backtrack(int index, vector<string>& current, string& s) {
        if (index == s.length()) {
            result.push_back(current);
            return;
        }

        for (int end = index; end < s.length(); ++end) {
            if (isPalindrome(s, index, end)) {
                current.push_back(s.substr(index, end - index + 1)); // choose
                backtrack(end + 1, current, s);                      // explore
                current.pop_back();                                  // un-choose
            }
        }
    }
};
