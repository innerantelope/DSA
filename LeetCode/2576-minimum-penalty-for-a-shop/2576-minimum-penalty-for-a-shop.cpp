class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> penalty(n + 1, 0);

        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }

        int currY = totalY;
        int currN = 0;

        for (int i = 0; i <= n; i++) {
            penalty[i] = currY + currN;
            if (i < n) {
                if (customers[i] == 'Y') currY--;
                else currN++;
            }
        }

        return min_element(penalty.begin(), penalty.end()) - penalty.begin();
    }
};
