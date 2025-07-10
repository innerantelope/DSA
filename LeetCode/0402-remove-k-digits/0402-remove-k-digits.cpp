class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (k == n)
            return "0";

        stack<char> st;

        for (char digits : num) {
            while (!st.empty() && st.top() > digits && k > 0) {
                st.pop();
                k--;
            }
            st.push(digits);
        }

        // Remove remaining digits if k > 0
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int start = 0;
        while (start < result.length() && result[start] == '0') {
            start++;
        }

        result = result.substr(start);
        return result.empty() ? "0" : result;
    }
};
