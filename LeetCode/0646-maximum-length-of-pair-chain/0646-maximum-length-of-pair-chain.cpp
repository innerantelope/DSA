class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int len=1;
        int curr=pairs[0][1];
        for(int i=0;i<pairs.size()-1;i++){
            if(pairs[i+1][0]>curr) {
                curr=pairs[i+1][1];
                len++;
            }
        }
        return len;
    }
};