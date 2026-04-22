class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+1,0);
        for(auto &b:bookings){
            int l=b[0]-1;
            int r=b[1]-1;
            int seats=b[2];
            diff[l]+=seats;
            if(r+1<n){
                diff[r+1]-=seats;
            }
        }
        vector<int>ans(n);
        ans[0]=diff[0];
        for(int i=1;i<n;i++){
            ans[i]=diff[i]+ans[i-1];
        }

        return ans;

        
    }
};