class Solution {
public:
   static bool compare(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort in each interval
        sort(intervals.begin(),intervals.end(),compare);
        int last_end=INT_MIN;
        int count=0;
        for(auto&interval:intervals){
            if(interval[0]>=last_end){
                last_end=interval[1];
            }
            else count++;

        }
        return count;
    }
};