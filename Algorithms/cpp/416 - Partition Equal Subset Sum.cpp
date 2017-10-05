class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // var
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum >> 1;
        vector<bool> dp(target + 1, 0);
        
        if (sum & 1)
            return false;
        
        // init
        dp[0] = 1;
        
        for (auto num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[target];
    }
};