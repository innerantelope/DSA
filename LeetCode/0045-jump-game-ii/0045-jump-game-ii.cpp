class Solution {
public:
    int jump(vector<int>& nums) {
        int far=0;
        int ans=0;
        int maxi=0;
        for(int i=0;i<nums.size()-1;i++){
            far=max(far,nums[i]+i);
            if(i==maxi){
                ans++;
                maxi=far;
            }
            

        }
        return ans;
    }
};