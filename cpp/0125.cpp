class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;

        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                v.push_back(tolower(s[i]));
            } else if (s[i] >= '0' && s[i] <= '9') {
                v.push_back(s[i]);
            }
        }

        for (int i = 0; i < v.size() >> 1; i++) {
            if (v[i] != v[v.size() - 1 - i]) {
                return false;
            }
        }
        
        return true;
    }
};
