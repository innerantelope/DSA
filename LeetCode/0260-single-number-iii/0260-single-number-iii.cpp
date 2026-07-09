class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(int x:nums){
            xr^=x;
        }
        unsigned int diff = (unsigned int)xr & (-(unsigned int)xr);
        int a=0,b=0;
        for(int x:nums){
            if(diff&x){
                a^=x;
            }
            else b^=x;
        }

        return {a,b};
        
    }
};