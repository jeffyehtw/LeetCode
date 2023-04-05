class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> umap;
        int index = 0;

        for (int i = 0; i < strs.size(); i++) {
            string s(26, 0);
            for (int j = 0; j < strs[i].length(); j++) {
                s[strs[i][j] - 'a']++;
            }

            if (umap.find(s) == umap.end()) {
                umap[s] = ret.size();
                ret.push_back(vector<string>());
            } 
            index = umap[s];
            ret[index].push_back(strs[i]);
        }

        return ret;
    }
};
