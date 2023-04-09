class Solution {
public:
    int longestPalindrome(string s) {
        int ret = 0;
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for (int i = 0; i < s.length(); i++) {
            if ((s[i] >= 'a') && (s[i] <= 'z')) {
                lower[s[i] - 'a']++;
            } else {
                upper[s[i] - 'A']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lower[i] > 1) {
                ret += lower[i] / 2;
                lower[i] %= 2;
            }
            if (upper[i] > 1) {
                ret += upper[i] / 2;
                upper[i] %= 2;
            }
        }
        ret *= 2;
        for (int i = 0; i < 26; i++) {
            if (lower[i] > 0) {
                ret++;
                break;
            }
            if (upper[i] > 0) {
                ret++;
                break;
            }
        }

        return ret;
    }
};
