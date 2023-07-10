class Solution {
private:
    int center(string s, int idx) {
        int ret = 0;
        int left = idx - 1;
        int right = idx + 1;
        
        while ((left > -1) && (right < s.length())) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
            ret++;
        }

        return ret;
    }
    int left(string s, int idx) {
        int ret = 0;
        int left = idx - 1;
        int right = idx;

        if (idx == 0) {
            return ret;
        }
        while ((left > -1) && (right < s.length())) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
            ret++;
        }

        return ret;
    }
    int right(string s, int idx) {
        int ret = 0;
        int left = idx;
        int right = idx + 1;

        if (idx >= s.length() - 1) {
            return ret;
        }
        while ((left > -1) && (right < s.length())) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
            ret++;
        }

        return ret;
    }
public:
    int countSubstrings(string s) {
        int ret = s.length();

        for (int i = 0; i < s.length(); i++) {
            ret += center(s, i);
            ret += left(s, i);
        }

        return ret;        
    }
};
