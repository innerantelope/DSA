class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int x:nums){
            int sum=0;
            while(x>0){
                int temp=x%10;
                sum+=temp;
                x=x/10;
            }
            if(sum<mini) mini=sum;
        }
        
        return mini;
    }
};