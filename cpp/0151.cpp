class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        int left = 0;
        int right = 0;

        for (; left < s.length(); left++) {
            if (isalpha(s[left]) || isdigit(s[left])) {
                break;
            }
        }
        right = left + 1;

        while (right < s.length()) {
            if (isalpha(s[right]) || isdigit(s[right])) {
                right++;
            } else {
                string sub(s.begin() + left, s.begin() + right);
                ret = sub + " " + ret;
                for (left = right + 1; left < s.length(); left++) {
                    if (isalpha(s[left]) || isdigit(s[left])) {
                        break;
                    }
                }
                right = left + 1;
            }
        }
        if (left < s.length()) {
            ret = string(s.begin() + left, s.begin() + right) + " " + ret;
        }
        if ((ret.length() > 0) && (ret[ret.length() - 1] == ' ')) {
            ret = string(ret, 0, ret.length() - 1);
        }
        
        return ret;
    }
};
