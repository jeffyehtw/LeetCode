class Solution {
private:
    vector<string> ret;
    void _letterCasePermutation(string s, int index) {
        if (index == s.length()) {
            ret.push_back(s);
            return;
        } else if (index > s.length() - 1) {
            return;
        }

        if (isalpha(s[index])) {
            _letterCasePermutation(s, index + 1);
            if (s[index] >= 'a' && s[index] <= 'z') {
                s[index] = toupper(s[index]);
                _letterCasePermutation(s, index + 1);
            } else {
                s[index] = tolower(s[index]);
                _letterCasePermutation(s, index + 1);
            }            
        } else {
            _letterCasePermutation(s, index + 1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        if (s.length() == 1) {
            
        }
        _letterCasePermutation(s, 0);
        return ret;
    }
};
