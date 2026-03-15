class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> total;
        unordered_map<int,int> f1;
        unordered_map<int,int> f2;
        for(int x: nums1){
            total[x]++;
            f1[x]++;
        }
        for(int x: nums2){
            total[x]++;
            f2[x]++;
        }

        for(auto &p : total){
            if(p.second % 2) return -1;
        }

        int ans = 0;

        for(auto &p : total){
            int val = p.first;
            int need = p.second / 2;

            if(f1[val] > need){
                ans += f1[val] - need;
            }
        }

        return ans;
    }
};