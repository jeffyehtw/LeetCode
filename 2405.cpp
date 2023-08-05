class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int ret = 0;
        int cnt = 0;
        vector<bool> used(26, false);

        for (int i = 0; i < n; i++) {
            if (used[s[i] - 'a']) {
                ret++;
                cnt = 0;
                used = vector<bool>(26, false);
            }
            used[s[i] - 'a'] = true;
            cnt++;
        }

        return ret + (cnt > 0);
    }
};
