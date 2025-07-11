class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices out of window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove elements smaller than current
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Store result after first window
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
