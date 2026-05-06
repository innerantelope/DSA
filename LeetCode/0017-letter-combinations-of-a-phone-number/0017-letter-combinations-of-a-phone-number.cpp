class Solution {
public:
    vector<string> ans;
    vector<string> map={
         "", "", "abc", "def","ghi", "jkl", "mno","pqrs", "tuv", "wxyz"
    };
    void solve(int index,string digits,  string temp) {
        if(index == digits.size()) {
            ans.push_back(temp);
            return;
        }
        int num = digits[index]-'0';
        string letters = map[num];
        for(char ch : letters) {
            solve(index + 1,digits, temp + ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        string temp;
        solve(0, digits,"");
        return ans;
    }
};