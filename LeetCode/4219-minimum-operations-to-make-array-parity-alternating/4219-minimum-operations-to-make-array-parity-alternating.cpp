class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        vector<int>v1,v2;
        for(int i=0;i<nums.size();i++){
            if((i+1)%2!=0){
                v1.push_back(nums[i]%2==0);
                v2.push_back(nums[i]%2!=0);
            }
            else{
                v1.push_back(nums[i]%2!=0);
                v2.push_back(nums[i]%2==0);
            }
        }
        int o=count(v1.begin(),v1.end(),1);
        int e=count(v2.begin(),v2.end(),1);

        cout<<"o: "<<o<<"e: "<<e<<"\n";
        int ans1=min(o,e);
        
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        int ans=INT_MAX;
        if(ans1==o){
            int m1=2,m2=2;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==maxi){
                    m1=min(v1[i],m1);
                }
                if(nums[i]==mini){
                    m2=min(v1[i],m2);
                }
            }
            ans=min(maxi-mini-(m1+m2),ans);
            
        }
        if(ans1==e){
            int m1=2,m2=2;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==maxi){
                    m1=min(v2[i],m1);
                }
                if(nums[i]==mini){
                    m2=min(v2[i],m2);
                }
            }
            // cout<<m1<<" "<<m2<<"\n";
            ans=min(maxi-mini-(m1+m2),ans);
            
        }
        if(maxi==mini && nums.size()>1){
            ans=1;
        }
        return {ans1,ans};
    }
};