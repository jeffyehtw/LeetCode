class Solution {
public:
    string originalDigits(string s) {
        string ret = "";
        vector<int> c(26, 0);
        vector<pair<string, char>> vp = {
            {"zero", '0'},
            {"xsi", '6'},
            {"geiht", '8'},
            {"seven", '7'},
            {"vfie", '5'},
            {"four", '4'},
            {"wto", '2'},
            {"three", '3'},
            {"one", '1'},
            {"inne", '9'}
        };

        for (int i = 0; i < s.length(); i++) {
            c[s[i] - 'a']++;
        }
        for (int i = 0; i < vp.size(); i++) {
            int cnt = c[vp[i].first[0] - 'a'];

            if (cnt <= 0) {
                continue;
            }
            ret += string(c[vp[i].first[0] - 'a'], vp[i].second);
            for (int j = 0; j < vp[i].first.length(); j++) {
                c[vp[i].first[j] - 'a'] -= cnt;
            }
        }
        sort(ret.begin(), ret.end());

        return ret;
    }
};
