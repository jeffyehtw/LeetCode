class Solution {
private:
    bool valid(vector<int>& window, int k) {
        for (int i = 0; i < window.size(); i++) {
            if (window[i] == 0) {
                continue;
            } else if (window[i] < k) {
                return false;
            }
        }
        return true;
    }
public:
    int longestSubstring(string s, int k) {
        int ret = 0;
        int i;
        int j;
        vector<int> cnt(26, 0);

        for (i = 0; i < s.length(); i++) {
            cnt[s[i] - 'a']++;
        }
        for (i = 0; i < s.length(); i++) {
            vector<int> window(26, 0);

            if (cnt[s[i] - 'a'] < k) {
                continue;
            }
            for (j = i; j < s.length(); j++) {
                if (cnt[s[j] - 'a'] < k) {
                    break;
                }
                window[s[j] - 'a']++;

                if (valid(window, k)) {
                    ret = max(ret, j - i + 1);
                }
            }
            if ((i == j) && valid(window, k)) {
                ret = max(ret, j - i + 1);
            }
        }

        return ret;
    }
};
