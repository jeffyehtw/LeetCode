class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        if (s.length() > t.length()) {
            return false;
        } else if (s.length() == t.length()) {
            return s == t;
        }

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        
        return (i == s.length());
    }
};
