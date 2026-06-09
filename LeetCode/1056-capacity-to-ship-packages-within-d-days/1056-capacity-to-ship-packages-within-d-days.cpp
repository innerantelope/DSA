class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long sum= accumulate(weights.begin(),weights.end(),0LL);
        int low=*max_element(weights.begin(),weights.end());
        int high=sum;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            int chk=0;
            int i=0;
            int day=1;
            while(i!=weights.size()-1){
                chk+=weights[i];
                if(chk+weights[i+1]>mid){
                    day++;
                    chk=0;
                } 
                i++;
            }
            if(day<=days){
             ans=min(ans,mid);
             high=mid-1;
            }
            else low=mid+1;

        }

        return ans;
        
    }
};