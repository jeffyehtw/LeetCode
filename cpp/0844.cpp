class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int del;
        int m = s.length();
        int n = t.length();
        int i;
        int j;
        vector<bool> vs(m, true);
        vector<bool> vt(n, true);

        del = 0;
        for (i = m - 1; i > -1; i--) {
            if (s[i] == '#') {
                del++;
                vs[i] = false;
            } else {
                if (del > 0) {
                    del--;
                    vs[i] = false;
                }
            }
        }
        del = 0;
        for (i = n - 1; i > -1; i--) {
            if (t[i] == '#') {
                del++;
                vt[i] = false;
            } else {
                if (del > 0) {
                    del--;
                    vt[i] = false;
                }
            }
        }

        for (i = 0, j = 0; ; i++, j++) {
            while (!vs[i] && (i < m)) {
                i++;
            }
            while (!vt[j] && (j < n)) {
                j++;
            }
            if (s[i] != t[j]) {
                return false;
            }
            if ((i >= m) && (j >= n)) {
                break;
            }
        }

        return (i == m) && (j == n);
    }
};
