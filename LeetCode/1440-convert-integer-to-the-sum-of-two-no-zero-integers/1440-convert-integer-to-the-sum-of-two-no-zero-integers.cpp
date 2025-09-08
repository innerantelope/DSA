class Solution {
public:
    bool hasnozero(int x) {
        while(x>0) {
            if(x%10==0) return true;
            x/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i=1;i<n;i++) {
            int j=n-i;
            if(!hasnozero(i) && !hasnozero(j)) {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        return ans;
    }
};