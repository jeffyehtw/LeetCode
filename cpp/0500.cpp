class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        string rows[3] = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        vector<int> map(26, -1);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < rows[i].length(); j++) {
                map[rows[i][j] - 'a'] = i;
            }
        }

        for (int i = 0; i < words.size(); i++) {
            bool ok = true;
            char f = tolower(words[i][0]);

            for (int j = 1; j < words[i].length(); j++) {
                char c = tolower(words[i][j]);

                if (map[f - 'a'] != map[c - 'a']) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ret.push_back(words[i]);
            }
        }

        return ret;
    }
};
