class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int n= INT_MAX,y=INT_MAX;
       for(int x:nums){
        if(x<=n) n=x;
        else if(x<=y) y=x;
        else return true;
       }

       return false;
        
    }
};