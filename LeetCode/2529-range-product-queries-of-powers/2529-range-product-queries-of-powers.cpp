class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>power;
        const int MOD=1e9+7;
        for(int i=0;i<31;i++){
            if(n & (1<<i)){
                power.push_back(1<<i);
            }
        }
        vector<int>answer;
        for(auto &q:queries){
            int left=q[0];
            int right=q[1];
            long long prod=1;
            for(int i=left;i<=right;i++){
                prod=(prod*power[i])%MOD;
            }
            answer.push_back((int)prod);
        }
    
        return answer;
    }
};