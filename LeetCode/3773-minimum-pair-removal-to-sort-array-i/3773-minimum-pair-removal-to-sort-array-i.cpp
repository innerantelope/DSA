class Solution {
public:
pair<int,int> min_sum(vector<int>&update){
        int sum =update[0]+update[1];
        pair<int,int>pair1={update[0],update[1]};
        for(int i=2;i<update.size();i++){
            int temp_sum = sum;
            int cur = update[i]+update[i-1];
            if(cur<temp_sum) {
                sum = cur;
                pair1.first=update[i-1];
                pair1.second=update[i];
            }
        }
        return pair1;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int min_op = 0;
        if(is_sorted(nums.begin(),nums.end())) return 0;
        vector<int>update(nums.begin(),nums.end());
        while(!(is_sorted(update.begin(),update.end()))){
            pair<int,int> p = min_sum(update);
            int idx = -1;
            for(int i=0;i<update.size();i++){
                if(p.first==update[i] && p.second==update[i+1]){
                    idx = i;
                    break;
                }
            }
            vector<int>next;
            for(int i=0;i<idx;i++){
                next.push_back(update[i]);
            }
            next.push_back(p.first+p.second);
            for(int i=idx+2;i<update.size();i++){
                next.push_back(update[i]);
            }
            update = next;
            min_op++;
            
        }

        return min_op;
        


    }
};