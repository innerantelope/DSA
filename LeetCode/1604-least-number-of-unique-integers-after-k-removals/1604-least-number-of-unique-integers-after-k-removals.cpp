class Solution {
public:
   static  bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int x:arr){
            mp[x]++;
        }
        vector<pair<int,int>>ans;
        for(auto &x:mp){
            ans.push_back({x.first,x.second});
        }
        sort(ans.begin(), ans.end(), compare);
         int unique = ans.size();
        for(auto &p : ans){
            if(k >= p.second){
                k -= p.second;
                unique--;
            } else break;
        }

        return unique;
         
        
    }
};