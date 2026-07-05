class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int ans=1;
        int curr=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>curr){
                ans++;
                curr=points[i][1];
            }
        }
        return ans;

        
    }
};