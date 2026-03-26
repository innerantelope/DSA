class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        if (n == 2 || n==1)
            return false;
        int alice = 0;
        int bob = 0;
        for (int i = 1; i < n - 1;i++) {
            if (colors[i] == 'A') {
                if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
                    alice++;
                }
                
        }
                if(colors[i] == 'B') {
                    if (colors[i] == colors[i - 1] &&
                        colors[i] == colors[i + 1]) {
                        bob++;
                    }
                }
         }
        if (alice > bob)
            return true;
        else if(alice==bob) return false;
        else
            return false;
    }
};