class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n);
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx= max(mx,nums[i]);
            pref[i]=gcd(nums[i],mx);
        }
        sort(pref.begin(),pref.end());
        long long sum=0;
        for(int i=0;i<nums.size()/2;i++){
            sum+=gcd(pref[i],pref[n-i-1]);
        }
        return sum;

        
    }
};