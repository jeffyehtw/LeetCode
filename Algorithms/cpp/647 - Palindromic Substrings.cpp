class Solution {
public:
    int countSubstrings(string s) {
        // var
        int result = 0;
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; j <= s.length() - i; j++) {
                if (isPalindromic(s.substr(i, j)))
                    result++;
            }
        }
        return result;
    }
private:
    bool isPalindromic(string s) {
        for (int i = 0; i < s.length() / 2; i++)
            if (s[i] != s[s.length() - 1 - i])
                return false;
        return true;
    }
};