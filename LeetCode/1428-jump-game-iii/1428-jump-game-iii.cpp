class Solution {
public:
    bool dfs(int i, vector<int>& nums, vector<int>& vis) {
        int n = nums.size();
        if(i < 0 || i >= n)
            return false;
        if(vis[i])
            return false;
        if(nums[i] == 0)
            return true;
        vis[i] = 1;
        return dfs(i + nums[i], nums, vis)||dfs(i - nums[i], nums, vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        return dfs(start, arr, vis);
    }
};