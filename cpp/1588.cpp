class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ret = 0;
        vector<int> dp(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); i++) {
            dp[i] += dp[i - 1];
        }
        ret = dp.back();
        for (int i = 3; i <= arr.size(); i += 2) {
            for (int j = 0; (i + j - 1) < arr.size(); j++) {
                ret += dp[i + j - 1] - ((j > 0) ? dp[j - 1] : 0);
            }
        }

        return ret;
    }
};
