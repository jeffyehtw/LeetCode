class Solution {
public:
    bool canPermutePalindrome(string s) {
        int ones = 0;
        vector<int> cnt(26, 0);

        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] & 1 == 1) {
                ones++;
            }
            if (ones > 1) {
                return false;
            }
        }

        return true;
    }
};
