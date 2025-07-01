class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, target, candidates, current, result);
        return result;
    }

private:
    void backtrack(int index, int target, vector<int>& candidates,
                   vector<int>& current, vector<vector<int>>& result) {
                    //base case
                    if(target==0){
                        result.push_back(current);
                        return;
                    }
                    if(index==candidates.size() || target<0){
                        return;
                    }
                    current.push_back(candidates[index]);//include
                    backtrack(index,target-candidates[index],candidates,current,result);
                    current.pop_back();
                    backtrack(index+1,target,candidates,current,result);//exclude
                   }



    };