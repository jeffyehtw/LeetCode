class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for (int i = 1; i <= n / 2; i++) {
            int idx = i;
            string cur = s.substr(0, i);

            if (n % cur.length() != 0) {
                continue;
            }
            for (; idx < n; idx += cur.length()) {
                if (cur != s.substr(idx, cur.length())) {
                    break;
                }
            }
            if (idx == s.length()) {
                return true;
            }
        }

        return false;
    }
};
