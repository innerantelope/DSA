class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        long long req=abs((long long)goal-sum);
        return ceil((double(req)/limit));
        
    }
};