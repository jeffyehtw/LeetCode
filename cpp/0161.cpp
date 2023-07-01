class Solution {
private:
    bool help(string s, int i, string t, int j, int chance) {
        int m = s.length();
        int n = t.length();
        bool ret = false;

        while ((i < m) && (j < n)) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                if (chance == 0) {
                    return false;
                }
                ret |= help(s, i, t, j + 1, chance - 1);
                ret |= help(s, i + 1, t, j, chance - 1);
                ret |= help(s, i + 1, t, j + 1, chance - 1);
                return ret;
            }
        }
        return (((i == m) && (j == n))
            || (m - i + n - j == chance));
    }
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length();
        int n = t.length();

        if ((s == t) || (abs(m - n) > 1)) {
            return false;
        }

        return help(s, 0, t, 0, 1);
    }
};
