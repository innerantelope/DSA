class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>pref(arr.size(),0);
        pref[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            pref[i]=pref[i-1]^arr[i];
        }
        vector<int>ans;
        for(auto &q:queries){
            if(q[0]==0) ans.push_back(pref[q[1]]);
            else ans.push_back(pref[q[1]]^pref[q[0]-1]);
        }
        return ans;
        

    }
};