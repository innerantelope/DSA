class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            while(nums[i]>0){
                temp.push_back(nums[i]%10);
                nums[i]=nums[i]/10;
            }
            reverse(temp.begin(),temp.end());
            for(int d:temp) ans.push_back(d);
        }

        return ans;
        
    }
};