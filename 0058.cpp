class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        int i = s.length() - 1;

        while (i > -1 && s[i] == ' ') {
            i--;
        }
        while (i > -1 && s[i] != ' ') {
            ret++;
            i--;
        }
        return ret;
    }
};
