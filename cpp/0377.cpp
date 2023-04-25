class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target + 1, 0);

        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i < nums[j]) {
                    break;
                } else if (i == nums[j]) {
                    dp[i] += 1;
                } else {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};
