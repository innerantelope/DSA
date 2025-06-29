class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {
        // Jab string complete ho jaaye
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Agar abhi tak n se kam '(' use hua hai
        if (open < n)
            backtrack(current + '(', open + 1, close, n);

        // Agar ')' abhi tak '(' se kam hai, toh hum use kar sakte hain
        if (close < open)
            backtrack(current + ')', open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n); // initial call
        return result;
    }
};