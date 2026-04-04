class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1= accumulate(nums1.begin(),nums1.end(),0LL);
        long long sum2= accumulate(nums2.begin(),nums2.end(),0LL);
        int count1 = count(nums1.begin(), nums1.end(), 0);
        int count2 = count(nums2.begin(), nums2.end(), 0);
        long long min1 = sum1 + count1;
        long long min2 = sum2 + count2;
        if(count1 == 0 && count2 == 0) {
            if(sum1 == sum2) return sum1;
            else return -1;
        }
        if(count1 == 0 && min2 > sum1) return -1;
        if(count2 == 0 && min1 > sum2) return -1;

        return max(min1,min2);

        
    }
};