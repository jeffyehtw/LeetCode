class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        int m[256] = { 0 };

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        for (int i = 0; i < s.length();) {
            int len = 1;
            int cur = m[s[i]];

            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    cur += m[s[j]];
                    len++;
                } else if (m[s[i]] < m[s[j]]) {
                    cur = -1 * cur + m[s[j]];
                    len++;
                    break;
                } else {
                    break;
                }
            }
            i += len > 0 ? len : 1;
            ret += cur;
        }
        
        return ret;
    }
};
