class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=arrays[0][0];
        int maxi=arrays[0].back();
        int ans=0;
        for(int i=1;i<arrays.size();i++){
            int curr_maxi=arrays[i].back();
            int curr_mini=arrays[i][0];

            ans=max(ans,max(abs(curr_maxi-mini),abs(curr_mini-maxi)));

            maxi=max(maxi,curr_maxi);
            mini=min(mini, curr_mini);

        }
        return ans;
    }
};