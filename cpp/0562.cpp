class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int ret = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    dp[i][j][k] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    continue;
                }
                if (i > 0) {
                    if (mat[i - 1][j] == 1) {
                        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + 1);
                    }
                    if ((j + 1 < n) && (mat[i - 1][j + 1] == 1)) {
                        dp[i][j][3] = max(dp[i][j][3], dp[i - 1][j + 1][3] + 1);
                    }
                }
                if (j > 0) {
                    if (mat[i][j - 1] == 1) {
                        dp[i][j][0] = max(dp[i][j][0], dp[i][j - 1][0] + 1);
                    }
                    if ((i > 0) && (mat[i - 1][j - 1] == 1)) {
                        dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][2] + 1);
                    }
                }
                
                for (int k = 0; k < 4; k++) {
                    ret = max(ret, dp[i][j][k]);
                }
            }
        }

        return ret;
    }
};
