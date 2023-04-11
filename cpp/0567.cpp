class Solution {
private:
    bool same(vector<int>& cnt) {
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] > 0) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        vector<int> cnt(26, 0);

        if (s1.length() > s2.length()) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            cnt[s1[i] - 'a']--;
            cnt[s2[i] - 'a']++;
        }
        if (same(cnt)) {
            return true;
        }

        for (int i = 1; i < s2.length() - n + 1; i++) {
            cnt[s2[i - 1] - 'a']--;
            cnt[s2[i + n - 1] - 'a']++;

            if (same(cnt)) {
                return true;
            }
        }

        return false;
    }
};
