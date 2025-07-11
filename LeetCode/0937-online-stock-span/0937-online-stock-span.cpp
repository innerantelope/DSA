class StockSpanner {
    stack<int> st;
    vector<int> prices;

public:
    StockSpanner() {}
    int next(int price) {
        int i = prices.size();
        prices.push_back(price);
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        int span;
        if (st.empty()) {
            span = i + 1;
        } else {
            span = i - st.top();
        }
        st.push(i);
        return span;
    }
};
