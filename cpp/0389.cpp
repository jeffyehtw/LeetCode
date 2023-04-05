class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;

        for (int i = 0; i < s.length(); i++) {
            ret ^= (s[i] - 'a');
            ret ^= (t[i] - 'a');
        }
        ret ^= (t[t.length() - 1] - 'a');

        return (ret + 'a');
    }
};
