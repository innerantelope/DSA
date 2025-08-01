class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle k > n

        queue<int> q;

        // Push last k elements into the queue
        for(int i = n - k; i < n; ++i){
            q.push(nums[i]);
        }

        // Push first n-k elements into the queue
        for(int i = 0; i < n - k; ++i){
            q.push(nums[i]);
        }

        // Refill nums from queue
        for(int i = 0; i < n; ++i){
            nums[i] = q.front();
            q.pop();
        }
    }
};
