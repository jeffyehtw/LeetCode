class Solution {
public:
    int lengthOfLastWord(string s) {
        // pre
        reverse(s.begin(), s.end());
        while (s[0] == ' ')
            s.assign(s, 1, s.length() - 1);
        
        if (s == "")
            return 0;
        
        // var
        int result = s.find(' ');
        
        return result > 0 ? result : s.length();
    }
};