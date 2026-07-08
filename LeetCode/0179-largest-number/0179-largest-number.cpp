class Solution {
public:
    static bool cmp(int a,int b){
        string p=to_string(a);
        string q=to_string(b);
        return p+q>q+p;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        if(nums[0]==0) return "0";
        string ans;
        for(int x:nums){
            ans+=to_string(x);
        }
        return ans;
    }
};