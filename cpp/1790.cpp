class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        pair<char, char> p;

        if (s1 == s2) {
            return true;
        }

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i]) {
                continue;
            } else {
                if (cnt == 0) {
                    p = make_pair(s1[i], s2[i]);
                } else if (cnt == 1) {
                    if ((p.first != s2[i]) || (p.second != s1[i])) {
                        return false;
                    }
                } else {
                    return false;
                }
                cnt++;
            }
        }

        return ((cnt == 0) || (cnt == 2));
    }
};
