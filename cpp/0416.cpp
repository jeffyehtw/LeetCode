class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        vector<vector<bool>> dp;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        
        sum /= 2;
        dp = vector<vector<bool>>(
            nums.size() + 1, 
            vector<bool>(sum + 1, false)
        );
        for (int i = 0; i < nums.size() + 1; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < sum + 1; i++) {
            dp[0][i] = false;
        }
        for (int i = 1; i < nums.size() + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (j - nums[i - 1] < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];   
                }
            }
        }

        return dp[nums.size()][sum];
    }
};
