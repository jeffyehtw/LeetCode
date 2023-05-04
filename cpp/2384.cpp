class Solution {
public:
    string largestPalindromic(string num) {
        string left = "";
        string right = "";
        string ret = "";
        vector<int> cnt(10, 0);
        int max = -1;
        int len = 0;

        for (int i = 0; i < num.length(); i++) {
            cnt[num[i] - '0']++;
        }
        for (int i = 9; i > -1; i--) {
            if (cnt[i] > 1) {
                left += string(cnt[i] / 2, '0' + i);
            }
            if ((max == -1) && (cnt[i] % 2 == 1)) {
                max = i;
            }
        }

        right = left;
        reverse(right.begin(), right.end());
        ret = left + ((max == -1) ? "" : to_string(max)) + right;

        for (; (len < ret.length() / 2) && (ret[len] == '0'); len++);
        ret = string(ret.begin() + len, ret.end() - len);

        return (ret == "") ? "0" : ret;
    }
};
