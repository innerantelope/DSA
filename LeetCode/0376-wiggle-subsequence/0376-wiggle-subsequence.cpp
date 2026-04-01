class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        vector<int> diff(n - 1);
        for(int i = 1; i < n; i++){
            diff[i - 1] = nums[i] - nums[i - 1];
        }

        int count = 1;
        int pos = -1; 

        for(int i = 0; i < diff.size(); i++){
            if(diff[i] > 0){
                pos = 0;
                count++;
                break;
            }
            else if(diff[i] < 0){
                pos = 1; 
                count++;
                break;
            }
        }

        for(int i = 0; i < diff.size(); i++){
            if(diff[i] < 0 && pos == 0){
                count++;
                pos = 1;
            }
            else if(diff[i] > 0 && pos == 1){
                count++;
                pos = 0;
            }
        }

        return count;
    }
};