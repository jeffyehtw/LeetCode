class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ret = INT_MAX;
        vector<vector<int>> dp(matrix.begin(), matrix.end());

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int _min = dp[i - 1][j];

                if (j > 0) {
                    _min = min(_min, dp[i - 1][j - 1]);
                }
                if (j + 1 < n) {
                    _min = min(_min, dp[i - 1][j + 1]);
                }
                dp[i][j] += _min;
            }
        }
        for (int i = 0; i < n; i++) {
            ret = min(ret, dp[n - 1][i]);
        }

        return ret;
    }
};
