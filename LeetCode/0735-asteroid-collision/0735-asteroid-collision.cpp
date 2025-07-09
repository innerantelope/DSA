class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n ; i++) {
            int curr = asteroids[i];
            while (!st.empty() && curr < 0 && st.top() > 0) {
                if (st.top() < -curr) {
                    st.pop();
                    continue;
                } else if (st.top() == -curr) {
                    st.pop();
                    curr = 0;
                    break;
                } else {
                    curr = 0;
                    break;
                }
            }
            if (curr != 0)
                st.push(curr);
        }
        vector<int> result(st.size());
        for (int i = st.size()-1; i>=0 ; i--) {
            result[i]=st.top();
            st.pop();
        }
        return result;
    }
};