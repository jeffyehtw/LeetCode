class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        int ret = 0;
        int cur = 0;
        vector<int> cnt(3, 0);

        if (s.length() < 3) {
            return 0;
        }

        while (right < s.length()) {
            cnt[s[right] - 'a']++;
            if (cnt[s[right] - 'a'] == 1) {
                cur++;
            }

            if (cur == 3) {
                ret += s.length() - right;
            }
            while (cur == 3) {
                cnt[s[left] - 'a']--;
                if (cnt[s[left] - 'a'] == 0) {
                    cur--;
                } else {
                    ret += s.length() - right;
                }
                left++;
            }
            right++;
        }

        return ret;
    }
};
