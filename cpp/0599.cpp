class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ret;
        int _min = INT_MAX;
        unordered_map<string, int> umap;

        for (int i = 0; i < list1.size(); i++) {
            umap[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i++) {
            if (umap.find(list2[i]) != umap.end()) {
                int idx = umap[list2[i]];

                if (_min > idx + i) {
                    _min = idx + i;
                    ret.clear();
                    ret.push_back(list2[i]);
                } else if (_min == idx + i) {
                    ret.push_back(list2[i]);
                }
            }
        }

        return ret;
    }
};
