class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>({ 0, 0 }));

        dp[0] = { 0, -prices[0] };
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }

        return max(dp.back()[0], dp.back()[1]);
    }
};
