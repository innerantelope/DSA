class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;

        // Push all elements of nums2 into the stack
        for (int i = 0; i < nums2.size(); ++i) {
            st.push(nums2[i]);
        }

        // Pop from stack and push into nums1
        while (!st.empty()) {
            nums1.push_back(st.top());
            st.pop();
        }

        // Sort merged array
        sort(nums1.begin(), nums1.end());

        int n = nums1.size();
        if (n % 2 == 1) {
            return nums1[n / 2]; // odd length
        } else {
            return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0; // even length
        }
    }
};
