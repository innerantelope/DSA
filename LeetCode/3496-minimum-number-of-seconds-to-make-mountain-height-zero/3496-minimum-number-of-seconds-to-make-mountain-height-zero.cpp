#define ll long long
class Solution {
    bool can(ll T,vector<int>&workerTimes,int mountainHeight){
        ll rem=0;
        for(ll t:workerTimes){
             ll val = (long long)(sqrt(1 + (8.0*T)/t) - 1) / 2;
             rem+=val;
             if(rem>=mountainHeight){
                return true;
             }
        }
        return false;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll left=0;
        ll right=1e18;
        ll ans=right;
        while(left<=right){
            ll mid=left +(right-left)/2;
            if(can(mid,workerTimes,mountainHeight)){
                ans=mid;
                right=mid-1;

            }
            else left=mid+1;
        }
        

        return ans;
        
    }
};