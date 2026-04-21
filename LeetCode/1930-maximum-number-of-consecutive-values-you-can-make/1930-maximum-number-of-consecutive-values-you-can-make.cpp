class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int res=1;
        for(int i:coins){
            if(i>res) break;
            res+=i;
        }

        return res;
        
    }
};