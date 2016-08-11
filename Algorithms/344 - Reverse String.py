class Solution {
public:
    string reverseString(string s) {
        string r = s;
        for(int i = 0; i < s.length(); i++)
            r[i] = s[s.length() - 1 - i];
        return r;
    }
};