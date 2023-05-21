class Solution {
public:
    int countGoodSubstrings(string s) {
        vector<bool> used(26, false);
        int left = 0;
        int right = 0;
        int ret = 0;

        while (right < s.length()) {
            while (used[s[right] - 'a'] || (right - left + 1) > 3) {
                used[s[left] - 'a'] = false;
                left++;
            }
            used[s[right] - 'a'] = true;
            if (right - left + 1 == 3) {
                ret++;
            }
            right++;
        }
        
        return ret;
    }
};
