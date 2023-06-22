class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ret(k, "");
        unordered_map<string, int> umap;
        vector<pair<int, string>> vp;

        for (int i = 0; i < words.size(); i++) {
            if (umap.find(words[i]) == umap.end()) {
                umap[words[i]] = 1;
            } else {
                umap[words[i]]++;
            }
        }
        for (auto it = umap.begin(); it != umap.end(); it++) {
            vp.push_back({ it->second, it->first });
        }
        sort(vp.begin(), vp.end(), [](pair<int, string> a, pair<int, string> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            } else {
                return a.first > b.first;
            }
        });
        for (int i = 0; i < ret.size(); i++) {
            ret[i] = vp[i].second;
        }

        return ret;
    }
};
