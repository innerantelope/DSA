class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())) return true;
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                count++;    
                if (i == 1 || nums[i] >= nums[i-2]) {
                nums[i-1] = nums[i];
                }
                else nums[i]=nums[i-1];
        }            
            if(count>1) return false;
           
        
        }
        return true;
        
    }
};