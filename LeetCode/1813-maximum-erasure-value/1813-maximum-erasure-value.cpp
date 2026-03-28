class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>st;
        long long maxi=0;
        long long sum=0;
        int left=0;
        for(int i=0;i<nums.size();i++){
            while(st.find(nums[i])!=st.end()){
                st.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            
            st.insert(nums[i]);
            sum+=nums[i];
            maxi= max(maxi,sum);


        }
        return maxi;
        
        
    }
};