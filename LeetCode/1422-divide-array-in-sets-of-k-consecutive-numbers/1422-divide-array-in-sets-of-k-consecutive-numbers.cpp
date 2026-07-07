class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;
        map<int,int>mp;
        for(int i:nums) mp[i]++;
        for(auto &it:mp){
            int num=it.first;
            int f=it.second;
            if(f==0) continue;
            for(int i=0;i<k;i++){
                if(mp[num+i]<f) return false;
                mp[num+i]-=f;
            }
        }
        return true;
    }
};