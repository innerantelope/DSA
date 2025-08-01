class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch national flag algo
        int l=0;int mid=0;int h=nums.size()-1;
        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[l++],nums[mid++]);
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[h--]);
            }


        }
    }
};