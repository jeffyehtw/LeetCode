class Solution {
private:
    vector<vector<int>> dp;
    bool backtrack(string s1, int i, string s2, int j, string s3, int k) {
        bool ret = false;

        if (k == s3.length()) {
            return true;
        } else if (dp[i][j] > -1) {
            return (dp[i][j] == 1) ? true : false;
        }

        if ((i < s1.length()) && (s1[i] == s3[k])) {
            ret |= backtrack(s1, i + 1, s2, j, s3, k + 1);
        }
        if ((j < s2.length()) && (s2[j] == s3[k])) {
            ret |= backtrack(s1, i, s2, j + 1, s3, k + 1);
        }

        dp[i][j] = (ret ? 1 : 0);

        return ret;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();

        if (m + n != s3.length()) {
            return false;
        }
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        
        return backtrack(s1, 0, s2, 0, s3, 0);
    }
};
