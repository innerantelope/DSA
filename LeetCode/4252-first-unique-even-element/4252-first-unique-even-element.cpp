class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
         unordered_map<int,int>mp;
         for(int i:nums){
            if(i%2==0){
                mp[i]++;
            }
         }

         int ans=-1;
         for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && mp[nums[i]]==1){
                 ans=nums[i];
                 break;
            }
         }
        return ans;
    
        
    }
};