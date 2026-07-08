class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum=(a+b+c);
        int mx=max({a,b,c});
        return min(sum/2,sum-mx);
    }
};