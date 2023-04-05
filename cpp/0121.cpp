class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tmp = 0;
        int ret = 0;
        vector<int> best(prices.size(), 0);

        for (int i = prices.size() - 1; i > -1; i--) {
            tmp = max(tmp, prices[i]);
            best[i] = tmp;
        }
        
        for (int i = 0; i < prices.size() - 1; i++) {
            ret = max(ret, best[i + 1] - prices[i]);
        }

        return ret;
    }
};
