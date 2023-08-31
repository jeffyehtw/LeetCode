class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long ret = nums[0];
        int n = nums.size();
        vector<long long> dp(n, INT_MIN);
        
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j > -1; j--) {
                if ((nums[i] & 1) ^ (nums[j] & 1)) {
                    dp[i] = max(dp[i], dp[j] + nums[i] - x);
                } else {
                    dp[i] = max(dp[i], dp[j] + nums[i]);
                    break;
                }
            }
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};
