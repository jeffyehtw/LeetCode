class Solution {
private:
    vector<string> ret;
    string cur = "";
    void help(string s, int idx) {
        if (idx == s.length()) {
            ret.push_back(cur);
            return;
        }
        if (isdigit(s[idx])) {
            cur += string(1, s[idx]);
            help(s, idx + 1);
            cur.pop_back();
        } else {
            cur += string(1, tolower(s[idx]));
            help(s, idx + 1);
            cur.pop_back();
            cur += string(1, toupper(s[idx]));
            help(s, idx + 1);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        help(s, 0);
        return ret;
    }
};
