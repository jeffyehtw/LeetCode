class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        help(S, 0);
        return result;
    }
    
    void help(string s, int idx) {
        if (idx == s.length()) {
            result.push_back(s);
            return;
        }
        
        if (isdigit(s[idx]))
            help(s, idx + 1);
        else {
            help(s, idx + 1);
            s[idx] = islower(s[idx]) ? s[idx] - 'a' + 'A' : s[idx] - 'A' + 'a';
            help(s, idx + 1);
        }
    }
private:
    vector<string> result;
};
