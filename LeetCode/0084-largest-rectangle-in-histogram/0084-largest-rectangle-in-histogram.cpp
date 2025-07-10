class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1), nse(n, n);
        stack<int> st;
        // pse
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()){
            st.pop();}
        // nse
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty())
                nse[i] = st.top();
            st.push(i);
        }

        long long maxArea = 0;
        for (int i = 0; i < n; ++i) {
            long long width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, 1LL * heights[i] * width);
        }
        return maxArea;
    }
};