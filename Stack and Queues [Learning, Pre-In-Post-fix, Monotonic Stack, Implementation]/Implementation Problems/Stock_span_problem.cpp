class StockSpanner {
public:
    stack<pair<int, int>> s;
    int idx;

    StockSpanner() : idx(-1) {}

    int next(int price) {
        idx++;
        while (!s.empty() && s.top().first <= price) {
            s.pop();
        }

        int ans = idx - (s.empty() ? -1 : s.top().second);
        s.push({price, idx});
        return ans;
    }
};
