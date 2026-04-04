class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count1=0;
        for(int i:nums){
            if(i==1) count1++;
        }
        if(count1>0) return nums.size()-count1;
        int mini= INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            int g=nums[i];
            for(int j=i;j<nums.size();j++){
                 g= __gcd(g,nums[j]);
                 if(g==1){
                    mini=min(mini,j-i+1);
                    break;
                 }
            }
        }

        if(mini==INT_MAX) return -1;
        else return (mini-1)+(nums.size()-1);

        
    }

        
        
};