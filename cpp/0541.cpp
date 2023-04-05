class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k) {
            int n = k > s.length() - i ? s.length() - i : k;
            for (int j = 0; j < n / 2; j++) {
                if ((i + j < s.length()
                    && (i + n - 1 - j < s.length()))) {
                    char c = s[i + j];
                    s[i + j] = s[i + n - 1 - j];
                    s[i + n - 1 - j] = c;
                }
            }
        }

        return s;
    }
};
