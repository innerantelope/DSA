class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int op=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto &it:mp){
            if(it.second==1){
                return -1;
                break;
            }
           op += (it.second + 2) / 3;  

        }

        return op;
    }
};