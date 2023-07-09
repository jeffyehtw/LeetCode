class Solution {
public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> umap;
        string ret = "";

        for (int i = 0; i < n; i++) {
            umap[words[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            string cur = words[i];

            if (ret.length() > cur.length()) {
                continue;
            }

            cur.pop_back();
            while (cur.length() > 0) {
                if (umap.find(cur) == umap.end()) {
                    break;
                }
                cur.pop_back();
            }
            if (cur.length() == 0) {
                if ((words[i].length() == ret.length())
                    && (words[i] < ret)) {
                    ret = words[i];
                } else if (words[i].length() > ret.length()) {
                    ret = words[i];
                }
            }
        }

        return ret;
    }
};
