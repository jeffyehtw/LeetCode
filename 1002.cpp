class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ret;
        vector<int> map(26, INT_MAX);

        for (int i = 0; i < words.size(); i++) {
            vector<int> tmp(26, 0);

            for (int j = 0; j < words[i].length(); j++) {
                tmp[words[i][j] - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                map[j] = min(map[j], tmp[j]);
            }
        }

        for (int i = 0; i < 26; i++) {
            if (map[i] > 0) {
                ret.insert(ret.end(), map[i], string(1, ('a' + i)));
            }
        }

        return ret;
    }
};
