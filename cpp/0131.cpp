class Solution {
private:
    vector<string> cur;
    vector<vector<string>> ret;
    bool palindrome(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    void backtrack(string s, int idx) {
        if (idx == s.length()) {
            ret.push_back(cur);
            return;
        }
        for (int i = 1; i <= s.length() - idx; i++) {
            string sub = string(s, idx, i);
            
            if (palindrome(sub)) {
                cur.push_back(sub);
                backtrack(s, idx + i);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ret;
    }
};
