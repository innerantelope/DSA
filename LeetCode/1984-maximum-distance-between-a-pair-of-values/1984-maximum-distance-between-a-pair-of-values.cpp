class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int left=0;
        int right=0;
        int maxi=0;
        while(left<nums1.size() && right<nums2.size()){
             if(nums2[right]>=nums1[left]) 
             {
             maxi=max(maxi,right-left);
             right++;
             }
             else {
                left++;
            
             }
       


        }
         return maxi;

        
    }
};