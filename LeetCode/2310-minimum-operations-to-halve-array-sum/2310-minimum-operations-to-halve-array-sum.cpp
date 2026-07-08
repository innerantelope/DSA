class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        int op=0;
        double sum= accumulate(nums.begin(),nums.end(),0.0);
        for(int x:nums){
            pq.push(x);
        }
        long long temp=sum;
        while(sum>double(temp/2.0)){
            double x=pq.top();
            pq.pop();
            double h=x/2.0;
            sum-=h;
            op++;
            pq.push(h);
        }

      return op;
        
    }
};