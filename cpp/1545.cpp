class Solution {
public:
    char findKthBit(int n, int k) {
        vector<pair<string, string>> vp;

        vp.push_back({ "0", "1" });
        for (int i = 1; i < n; i++) {
            string s = vp.back().second;
            string invert = "";

            reverse(s.begin(), s.end());
            s = vp.back().first + "1" + s;
            for (int j = 0; j < s.length(); j++) {
                invert += string(1, s[j] == '1' ? '0' : '1');
            }
            vp.push_back(make_pair(s, invert));
        }

        return vp.back().first[k - 1];
    }
};
