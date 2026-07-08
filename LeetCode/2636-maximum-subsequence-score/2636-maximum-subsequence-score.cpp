class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back({nums1[i],nums2[i]});
        }
        priority_queue<int,vector<int>,greater<int>>mini;
        long long curr=0;
        long long maxi=0;
        sort(ans.begin(),ans.end(),cmp);
        for(int i=ans.size()-1;i>=0;i--){
            curr+=ans[i].first;
            mini.push(ans[i].first);
            if(mini.size()>k){
                curr-=mini.top();
                mini.pop();
            }
            if(mini.size()==k){
                long long curs=curr*ans[i].second;
                maxi=max(maxi,curs);
            }

        }
        return maxi;

        
    }
};