class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size();
        vector<int> idx(n, 0);
        string ret = "";

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < n; j++) {
                if (idx[j] >= dictionary[j].length()) {
                    continue;
                }
                if (s[i] == dictionary[j][idx[j]]) {
                    idx[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (idx[i] == dictionary[i].length()) {
                if (ret.length() < idx[i]) {
                    ret = dictionary[i];
                } else if ((ret.length() == idx[i])
                    && (ret > dictionary[i])) {
                    ret = dictionary[i];
                }
            }
        }

        return ret;
    }
};
