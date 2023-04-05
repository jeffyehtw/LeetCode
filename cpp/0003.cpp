class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int ret = 1;
        int left = -1;

        if (s.length() <= 1) {
            return s.length();
        }

        for (int i = 0; i < s.length(); i++) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];
            }
            m[s[i]] = i;
            ret = max(ret, i - left);
        }

        return ret;
    }
};