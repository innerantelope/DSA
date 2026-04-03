class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        long long sumb=0;
        sort(piles.begin(),piles.end());
        for(int i=0;i<n/3;i++){
            sumb+=piles[i];
        }
        long long suma=0;
        for(int i=n-1;i>n/3;i=i-2){
            suma+=piles[i];

        }
        long long total=accumulate(piles.begin(),piles.end(),0LL);
        return total-suma-sumb;

        
    }
};