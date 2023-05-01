class Solution {
public:
    int minAddToMakeValid(string s) {
        int ret = 0;
        int left = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                if (left <= 0) {
                    ret++;
                } else {
                    left--;
                }
            }
        }
        ret += left;

        return ret;
    }
};
