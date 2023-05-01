class Solution {
public:
    int minInsertions(string s) {
        int ret = 0;
        int left = 0;

        for (int i = 0; i < s.length(); ) {
            if (s[i] == '(') {
                left++;
                i++;
            } else if (s[i] == ')') {
                if (left > 0) {
                    left--;
                } else {
                    ret++;
                }
                if ((i + 1 < s.length()) && (s[i + 1] == ')')) {
                    i += 2;
                } else {
                    i++;
                    ret++;
                }
            }
        }
        if (left > 0) {
            ret += (left << 1);
        }

        return ret;
    }
};
