class Solution {
private:
    vector<vector<string>> ret;
    bool palindrome(string s) {
        int n = s.length() - 1;

        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[n - i]) {
                return false;
            }
        }

        return true;
    }
    void backtrack(string s, int index, vector<string> ss) {
        int len = s.length() - index;

        if (len < 0) {
            return;
        } else if (len == 0) {
            ret.push_back(ss);
            return;
        }

        for (int i = 1; i <= len; i++) {
            string sub(s, index, i);
            if (palindrome(sub)) {
                ss.push_back(string(s, index, i));
                backtrack(s, index + i, ss);
                ss.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> ss;
        backtrack(s, 0, ss);
        return ret;
    }
};
