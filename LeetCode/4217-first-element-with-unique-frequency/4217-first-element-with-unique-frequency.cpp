class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<pair<int,int>>ans;
        for(int num:nums){
            ans.push_back({num,freq[num]});
        }
        unordered_map<int,int>frq_count;
        for(auto& p:freq){
            frq_count[p.second]++;
        }
        for(auto &p:ans){
            if(frq_count[p.second]==1){
                return p.first;
            }
        }

        return -1;

      

     
    }
};