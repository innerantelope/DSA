class Solution {
public:
    using ll=long long;
    int maxProduct(vector<int>& nums) {
         ll lp=1;
         ll rp=1;
         ll ans=nums[0];
         ll j=0;
        while(j<nums.size()){
            if(lp==0) lp=1;
            if(rp==0) rp=1;
            lp*=nums[j];
            rp*=nums[nums.size()-1-j];
            ans=max(ans,max(lp,rp));
            j++;
        }

         return ans;

        
    }
};