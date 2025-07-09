class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long mod = 1e9 + 7;
        stack<int> st;
        vector<int> prev(n, -1), next(n, n);
        for (int i = 0 ;i<n ; i++) { // pse
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();}
                if (!st.empty())
                    prev[i] = st.top();
                st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n-1; i >=0; i--) { // nse
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();}
                if (!st.empty())
                    next[i] = st.top();
                st.push(i);
            }
        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            result = (result + arr[i] * left * right) % mod;
        }
        return result;
    }
};