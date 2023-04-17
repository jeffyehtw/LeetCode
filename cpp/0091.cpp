class Solution {
private:
    bool valid(string s, int idx) {
        if (s[idx - 1] == '1') {
            return true;
        } else if (s[idx - 1] == '2') {
            return (s[idx] >= '0') && (s[idx] <= '6');
        } else {
            return false;
        }
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);

        dp[0] = 1;
        dp[1] = (s[0] >= '1') && (s[0] <= '9');
        for (int i = 2; i < dp.size(); i++) {
            if ((s[i - 1] >= '1') && (s[i - 1] <= '9')) {
                dp[i] += dp[i - 1];
            }
            if (valid(s, i - 1)) {
                dp[i] += dp[i - 2];
            }         
        }

        return dp.back();
    }
};
