class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);

        dp[0] = true;
        for (int i = 1; i < dp.size(); i++) {
            int ok = false;

            for (int j = 0; j < wordDict.size() && !ok; j++) {
                int idx = i - wordDict[j].length();

                if ((idx > -1) && (dp[idx] == true)) {
                    string sub(s, idx, wordDict[j].length());
                    
                    if (sub == wordDict[j]) {
                        dp[i] = true;
                    }
                }
            }
        }

        return dp.back();
    }
};
