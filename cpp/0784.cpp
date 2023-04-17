class Solution {
private:
    vector<string> ret;
    void backtrack(string s, int idx) {
        if (idx == s.length()) {
            ret.push_back(s);
            return;
        }

        if ((s[idx] >= 'a') && (s[idx] <= 'z')) {
            backtrack(s, idx + 1);
            s[idx] = toupper(s[idx]);
            backtrack(s, idx + 1);
        } else if ((s[idx] >= 'A') && (s[idx] <= 'Z')) {
            backtrack(s, idx + 1);
            s[idx] = tolower(s[idx]);
            backtrack(s, idx + 1);
        } else {
            backtrack(s, idx + 1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0);
        return ret;
    }
};
