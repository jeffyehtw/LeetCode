class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1);
        vector<int> squres;

        for (int i = 0; i * i <= n; i++) {
            squres.push_back(i * i);
        }

        if (n <= 3) {
            return n;
        }

        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            if ((int)pow(i, 0.5) * pow(i, 0.5) == i) {
                continue;
            }
            dp[i] = i;
            for (int j = 0; j < squres.size(); j++) {
                if (squres[j] >= i) {
                    break;
                }
                dp[i] = min(dp[i], dp[squres[j]] + dp[i - squres[j]]);
            }
        }

        return dp.back();
    }
};
