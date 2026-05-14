class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i:nums){
            if(i>=ans.size()) return false;
            ans[i]++;
        }
        for(int i=1;i<n-1;i++){
            if(ans[i]>1) return false;
        }
        if(ans[n-1]!=2) return false;
        return true;


    }
};