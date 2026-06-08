class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>left;
        vector<int>right;
        int count_pivot=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) left.push_back(nums[i]);
            else if(nums[i]>pivot) right.push_back(nums[i]);
            else count_pivot++;
        }
        int i=0;
        for(int j=0;j<left.size();j++){
            nums[i]=left[j];
            i++;
        }
        while(count_pivot--){
            nums[i]=pivot;
            i++;
        }
         for(int j=0;j<right.size();j++){
            nums[i]=right[j];
            i++;
        }
        return nums;
    }
};