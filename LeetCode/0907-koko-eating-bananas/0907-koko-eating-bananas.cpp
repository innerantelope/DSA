class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int x=*max_element(piles.begin(),piles.end());
        int high=x;
        int low=1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            long long total=0;
            for(int pile:piles){
                total+=(pile+mid-1)/mid;
            }
            if(total<=h){
            ans=min(ans,mid);
            ans=mid;
            high=mid-1;
            }
            else {
                low=mid+1;
            }

        }

        return ans;
        
    }
};