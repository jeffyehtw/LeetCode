class Solution {
public:
    bool isPalindrome(string s) {
        // remove illegal
        for (int i = 0; i < s.length(); ) {
            if (!isalpha(s[i]) && !isdigit(s[i]))
                s.erase(s.begin() + i);
            else {
                s[i] = isalpha(s[i]) ? tolower(s[i]) : s[i];
                i++;
            }
        }
        
        // check
        for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - 1 - i])
            return false;
        return true;
    }
};