class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int can1=0,can2=1;
        for(int num:nums){
            if(num==can1) cnt1++;
            else if(num==can2) cnt2++;
            else if(cnt1==0){
            can1=num; 
            cnt1=1;
        }
            else if(cnt2==0){
                can2=num; 
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }

        }
        cnt1=cnt2=0;
        for(int num:nums){
            if(num==can1) cnt1++;
            else if(num==can2) cnt2++;
        }
        vector<int>ans;
        if(cnt1>nums.size()/3) ans.push_back(can1);
        if(cnt2>nums.size()/3) ans.push_back(can2);
        
        return ans;
    }
};