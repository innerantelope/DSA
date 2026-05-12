class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int sum=0;
        for(auto &i:tasks){
            sum+=i[0];
        }
       int temp=sum;
       sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b){
         return (a[1] - a[0]) > (b[1] - b[0]);
       });
       for(auto &i:tasks){
        if(sum>=i[1]) sum=sum-i[0];
        else {
        int x=i[1]-sum;
        temp+=x;
        sum+=x;
        sum-=i[0];
        }
       }
       return temp;

        
    }
};