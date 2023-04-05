class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ret = 0;
        unordered_map<string, int> umap1;
        unordered_map<string, int> umap2;

        for (int i = 0; i < words1.size(); i++) {
            if (umap1.find(words1[i]) == umap1.end()) {
                umap1[words1[i]] = 0;
            }
            umap1[words1[i]]++;
        }
        for (int i = 0; i < words2.size(); i++) {
            if (umap2.find(words2[i]) == umap2.end()) {
                umap2[words2[i]] = 0;
            }
            umap2[words2[i]]++;
        }

        for (auto i = umap1.begin(); i != umap1.end(); i++) {
            if ((i->second == 1)
                && (umap2.find(i->first) != umap2.end())
                && (umap2[i->first] == 1)) {
                ret++;
            } 
        }

        return ret;
    }
};
