class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int len;

        dp[0][0] = (matrix[0][0] == '1' ? 1 : 0);
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][0] += (matrix[i][0] == '1' ? 1 : 0);
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1];
            dp[0][i] += (matrix[0][i] == '1' ? 1 : 0);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] -= dp[i - 1][j - 1];
                dp[i][j] += (matrix[i][j] == '1' ? 1 : 0);
            }
        }
        if (dp[m - 1][n - 1] == 0) {
            return 0;
        }

        for (len = 2; ; len++) {
            bool found = false;
            for (int i = len - 1; (i < m) && !found; i++) {
                for (int j = len - 1; (j < n) && !found; j++) {
                    int upper = (i >= len) ? dp[i - len][j] : 0;
                    int left = (j >= len) ? dp[i][j - len] : 0;
                    int repeat = ((i >= len) && (j >= len)) ? dp[i - len][j - len] : 0;

                    if (dp[i][j] - upper - left + repeat == len * len) {
                        found = true;
                    } 
                }
            }

            if (found == false) {
                break;
            }
        }

        return (len - 1) * (len - 1);
    }
};
