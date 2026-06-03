class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landDuration.size();
        int m=waterStartTime.size();

        int ans=INT_MAX;
        //start by land
        int earliestland=INT_MAX;
        for(int i=0;i<n;i++){
            if(landStartTime[i]+landDuration[i]<earliestland) 
                earliestland=landStartTime[i]+landDuration[i];
        }
        int newtime=earliestland;
        for(int i=0;i<m;i++){
            int final=earliestland+max(waterStartTime[i]-newtime,0)+waterDuration[i];
            ans=min(ans,final);
        }
        //start by water
        int earliestwater=INT_MAX;
        for(int i=0;i<m;i++){
            if(waterStartTime[i]+waterDuration[i]<earliestwater) 
                earliestwater=waterStartTime[i]+waterDuration[i];
        }
        newtime=earliestwater;
        for(int i=0;i<n;i++){
            int final=earliestwater+max(landStartTime[i]-newtime,0)+landDuration[i];
            ans=min(ans,final);
        }
        return ans;
    }
};