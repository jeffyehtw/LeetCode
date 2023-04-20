class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);

        for (int i = 3; i < n; i++) {
            dp[i] = i;
        }
        if (n <= 2) {
            return dp[n];
        }
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(
                    dp[i], 
                    max(j, dp[j]) * max(i - j, dp[i - j])
                );
            }
        }

        return dp[n];
    }
};
