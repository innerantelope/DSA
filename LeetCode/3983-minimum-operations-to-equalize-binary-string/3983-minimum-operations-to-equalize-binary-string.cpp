class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();

        int zeros = 0;
        for (char c : s) {
            if (c == '0') zeros++;
        }

        if (zeros == 0) return 0; 
        if (k == 0) return -1;    

        for (int ops = 1; ops <= n; ops++) {
            int totalFlips = ops * k;

            if (totalFlips < zeros) continue;

            if ((totalFlips - zeros) % 2 != 0) continue;

            return ops; 
        }

        return -1; 
    }
};
