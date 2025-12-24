class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum_apples = accumulate(apple.begin(),apple.end(),0);

        sort(capacity.rbegin(),capacity.rend());
        long long sum =0;
        for(int i =0;i<capacity.size();i++){
            sum+=capacity[i];
            if(sum>=sum_apples){
                return i+1;
                break;
            }
            
               
        }

        return 0;
    }
};