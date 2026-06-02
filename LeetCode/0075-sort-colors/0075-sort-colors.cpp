class Solution {
public:
    void sortColors(vector<int>& nums) {
        int o=0,z=0,t=0;
        for(int i:nums){
            if(i==1) o++;
            else if(i==0) z++;
            else t++;
        }
        int idx = 0;
        while (z--) nums[idx++] = 0;
        while (o--) nums[idx++] = 1;
        while (t--) nums[idx++] = 2;

    }
};