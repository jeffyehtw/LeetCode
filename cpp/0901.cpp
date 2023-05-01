class StockSpanner {
private:
    int idx;
    stack<pair<int, int>> last;
public:
    StockSpanner() {
        idx = 0;
        last = stack<pair<int, int>>();
    }
    
    int next(int price) {
        int ret = 0;

        while(!last.empty() && (last.top().first <= price)) {
            last.pop();
        }
        if (!last.empty()) {
            ret += idx - last.top().second;
        } else {
            ret = idx + 1;
        }
        last.push(make_pair(price, idx));
        idx++;

        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
