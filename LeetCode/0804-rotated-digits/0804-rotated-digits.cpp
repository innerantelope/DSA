class Solution {
public:
    bool good(int p) {
        bool check = false;
        while (p > 0) {
            int x = p % 10;
            if(x==3 || x==4 || x==7){
                return false;
            }
            if (x == 2 || x == 5 || x == 6 || x == 9) {
                check = true;
            }
            p= p / 10;
        }
        return check;
    }
    int rotatedDigits(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            if(good(i)) count++;
            else continue;
        }
        return count;
    }
};