class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //dp[i]=subset sum that equals to total/2
        int total=accumulate(stones.begin(),stones.end(),0);
        vector<bool>dp(total/2+1,false);
        dp[0]=true;
        for(int stone:stones){
            for(int i=total/2;i>=stone;i--){
                dp[i]=dp[i]||dp[i-stone];

            }
        }
        int s=0;
        for(int i=1;i<=total/2;i++){
            if(dp[i]) s=i; 
        }
        return total-2*s;

        
    }
};