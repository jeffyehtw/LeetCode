class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;
        
        // var
        vector<int> dp({ 0 });
        
        // init
        for (int i = 0; i < nums.size(); i++)
            dp.push_back(dp[i] + nums[i]);
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = i + 1; j < dp.size(); j++) {
                if (k && (dp[j] - dp[i - 1]) % k == 0)
                    return true;
                else if (!k && dp[j] - dp[i - 1] == 0)
                    return true;
            }
        }        
        return false;
    }
};