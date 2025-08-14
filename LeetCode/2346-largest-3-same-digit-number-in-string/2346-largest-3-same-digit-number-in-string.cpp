class Solution {
public:
    string largestGoodInteger(string num) {
        int left = 0;
        int right = left + 2;
        string maxgood = "";
        while (right < num.length()) {
            string good = num.substr(left, 3);
            if (good[0] == good[1] && good[0] == good[2]) {
                if (good > maxgood) maxgood = good;
            }
            left++;
            right++;
        }
        return maxgood;
    }
};
