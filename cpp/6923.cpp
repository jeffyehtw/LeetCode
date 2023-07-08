class Solution {
private:
    int ret = INT_MAX;
    int dec(string s, int left, int right) {
        int val = 0;

        for (int i = left; i <= right; i++) {
            val <<= 1;
            val |= (s[i] - '0');
        }
        
        return val;
    }
    bool valid(string s, int left, int right) {
        int val = 0;
        
        if (s[left] == '0') {
            return false;
        }
        for (int i = left; i <= right; i++) {
            val <<= 1;
            val |= (s[i] - '0');
        }
        while (val > 1) {
            if (val % 5 > 0) {
                return false;
            }
            val /= 5;
        }
        
        return true;
    }
    void backtrack(string s, int idx, int count) {
        if (idx >= s.length()) {
            ret = min(ret, count);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            if (valid(s, idx, i)) {
                backtrack(s, i + 1, count + 1);
            }
        }
    }
public:
    int minimumBeautifulSubstrings(string s) {
        if (s.length() == 1) {
            return (s[0] == '1') ? 1 : -1;
        }
        backtrack(s, 0, 0);
        return (ret == INT_MAX) ? -1 : ret;
    }
};
