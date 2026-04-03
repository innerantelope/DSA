class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long count=0;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                continue;
            }
            else{
                 int k = (nums[i]+nums[i+1]-1)/nums[i+1];
                  count += (k - 1);
                  nums[i] = nums[i] / k;
            }

        }
        return count;
        
    }
};