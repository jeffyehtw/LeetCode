class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> map(256, 0);
        vector<bool> sseen(256, false);
        vector<bool> tseen(256, false);

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (sseen[s[i]]) {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if (tseen[t[i]]) {
                    return false;
                } else {
                    sseen[s[i]] = true;
                    tseen[t[i]] = true;
                    map[s[i]] = t[i];
                }
            }
        }

        return true;
    }
};
