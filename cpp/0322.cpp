class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);

        if (amount == 0) {
            return 0;
        } else if (amount < 0) {
            return -1;
        }

        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            int _min = INT_MAX;

            for (int j = 0; j < coins.size(); j++) {
                if ((i - coins[j] > -1) && (dp[i - coins[j]] > -1)) {
                    _min = min(_min, 1 + dp[i - coins[j]]);
                }
            }

            dp[i] = (_min == INT_MAX) ? -1 : _min;
        }

        return dp[amount];
    }
};
