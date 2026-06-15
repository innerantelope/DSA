class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i:nums){
            int x=k-i;
            if(mp[x] > 0){
                ans++;
                mp[x]--;
            }
            else 
               mp[i]++;
        }
        return ans;
        
    }
};