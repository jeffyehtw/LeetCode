class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int left = 0;
        int right = 0;
        vector<bool> used(26, false);
        int ret = 0;

        while (right < s.length()) {
            if (used[s[right] - 'a']) {
                while (used[s[right] - 'a']) {
                    used[s[left] - 'a'] = false;
                    left++;
                }
            }
            used[s[right] - 'a'] = true;
            while (right - left + 1 > k) {
                used[s[left] - 'a'] = false;
                left++;
            }

            if (right - left + 1 == k) {
                ret++;
            }
            right++;
        }

        return ret;
    }
};
