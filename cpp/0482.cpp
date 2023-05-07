class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ret = "";
        string valid = "";
        int idx;

        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                valid += string(1, toupper(s[i]));
            } else if (isdigit(s[i])) {
                valid += string(1, s[i]);
            }
        }
        if (valid.length() % k == 0) {
            idx = k;
        } else {
            idx = valid.length() % k;
        }
        ret += string(valid, 0, idx);

        for (; idx < valid.length(); idx += k) {
            ret += "-" + string(valid, idx, k);
        }

        return ret;
    }
};
