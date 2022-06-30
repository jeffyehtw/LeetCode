class Solution {
public:
    vector<vector<string>> partition(string s) {
        // var
        vector<vector<string>> result;
        helper(s, vector<string>(), result);
        return result;
    }
    
    void helper(string s, vector<string> current, vector<vector<string>>& result) {
        if (s.length() == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = 1; i < s.length() + 1; i++) {
            // var
            if (!is_palindrome(s.substr(0, i))) {
                continue;
            }
            current.push_back(s.substr(0, i));
            helper(s.substr(i), current, result);
            current.pop_back();
        }
    }
    
    bool is_palindrome(string s) {
        for (int i = 0; i < s.length() / 2 + 1; i++)
            if (s[i] != s[s.length() - 1 - i])
                return false;
        return true;
    }
};