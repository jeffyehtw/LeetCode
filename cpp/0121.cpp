class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // var
        int profit = 0;
        int min_val = INT_MAX;
        
        for (int i = 0; i < prices.size(); i++) {
            min_val = min(min_val, prices[i]);
            profit = max(profit, prices[i] - min_val);
        }
        return profit;
    }
};