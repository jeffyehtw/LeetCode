class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 1;
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) {
                    continue;
                }
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};
