class Solution {
public:
    int nthUglyNumber(int n) {
        // var
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> dp({ 1 });
        
        while (dp.size() < n) {
            dp.push_back(min(dp[i] * 2, min(dp[j] * 3, dp[k] * 5)));
            i += dp.back() == dp[i] * 2;
            j += dp.back() == dp[j] * 3;
            k += dp.back() == dp[k] * 5;
        }
        return dp[n - 1];
    }
};