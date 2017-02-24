class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // var
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // init
        for (int i = 0; i < n && !obstacleGrid[0][i]; i++)
            dp[0][i] = 1;
        for (int i = 0; i < m && !obstacleGrid[i][0]; i++)
            dp[i][0] = 1;
        
        // run
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j])
                    continue;
                dp[i][j] += obstacleGrid[i - 1][j] ? 0 : dp[i - 1][j];
                dp[i][j] += obstacleGrid[i][j - 1] ? 0 : dp[i][j - 1];
            }
        }
        return dp.back().back();
    }
};