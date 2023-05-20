class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> umap;
        vector<string> ret;
        string cur = "";

        if (s.length() < 10) {
            return ret;
        }

        cur = string(s, 0, 10);
        umap[cur] = 1;
        for (int i = 1; i < s.length() - 10 + 1; i++) {
            cur = string(s, i, 10);
            if (umap.find(cur) == umap.end()) {
                umap[cur] = 1;
            } else {
                if (umap[cur] == 1) {
                    ret.push_back(cur);
                }
                umap[cur]++;
            }
        }

        return ret;
    }
};
