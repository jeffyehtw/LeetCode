class Solution {
private:
    string palindrome(string s, int left, int right) {
        if ((left < 0) || (right >= s.length())) {
            return "";
        }

        while ((left > -1) && (right < s.length()) && (s[left] == s[right])) {
            left--;
            right++;
        }

        return string(s.begin() + left + 1, s.begin() + right);
    }
public:
    string longestPalindrome(string s) {
        string ret = "";

        for (int i = 0; i < s.length(); i++) {
            string s1 = "";
            string s2 = "";
            
            s1 = palindrome(s, i, i);
            if (s[i] == s[i + 1]) {
                s2 = palindrome(s, i, i + 1);
            }

            ret = (ret.length() > s1.length()) ? ret : s1;
            ret = (ret.length() > s2.length()) ? ret : s2;
        }

        return ret;
    }
};
