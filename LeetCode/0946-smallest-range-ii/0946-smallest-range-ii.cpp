class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int p=(*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end()));
        // if(nums.size()%2==0){
        // for(int i=0;i<nums.size()/2;i++){
        //     nums[i]=nums[i]+k;
        // }
        // for(int i=nums.size()/2;i<nums.size();i++){
        //     nums[i]=nums[i]-k;
        // }
        // }
        // if(nums.size()%2==1){
        //  for(int i=0;i<=nums.size()/2;i++){
        //     nums[i]=nums[i]+k;
        // }
        // for(int i=nums.size()/2+1;i<nums.size();i++){
        //     nums[i]=nums[i]-k;
        // }
        // }
        for(int i=0;i<nums.size()-1;i++){
            int currm=max(nums[nums.size()-1]-k,nums[i]+k);
            int currn=min(nums[0]+k,nums[i+1]-k);
            p=min(p,currm-currn);
        }
        return p;

        // sort(nums.begin(),nums.end());
        // if(nums.size()>=3) return nums[nums.size()-1]-nums[nums.size()-2];
        // else if(nums.size()==2)return (nums[nums.size()-1]-k)-(nums[nums[0]]+k);
        // else return 0;
        
        
    }
};