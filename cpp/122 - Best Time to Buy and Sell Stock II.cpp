class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // var
        int profit = 0;
        int n = prices.size();
        
        for (int i = 1; i < n; i++) {
            // var
            int tmp = prices[i] - prices[i - 1];
            profit += tmp > 0 ? tmp : 0;
        }
        return profit;
    }
};