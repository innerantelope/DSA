class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        int sum=0;
        int maxfruit=0;
        int left=0;
        for(int right=0;right<n;right++){
            sum+=fruits[right][1];
            while(left<=right){
                int leftpos=fruits[left][0];
                int rightpos=fruits[right][0];
                int dist=min(abs(startPos-leftpos)+(rightpos-leftpos),abs(startPos-rightpos)+(rightpos-leftpos));
                if(dist<=k) break;
                sum-=fruits[left][1];
                left++;
            }
            maxfruit=max(maxfruit,sum);
        }
        return maxfruit;
    }
};