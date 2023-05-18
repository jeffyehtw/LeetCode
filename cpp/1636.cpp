class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<pair<int, int>> vp;
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = 1;
            } else {
                umap[nums[i]]++;
            }
        }
        for (auto it = umap.begin(); it != umap.end(); it++) {
            vp.push_back(make_pair(it->first, it->second));
        }
        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
            return (a.second == b.second) ? (a.first > b.first) : (a.second < b.second);
        });
        for (int i = 0; i < vp.size(); i++) {
            ret.insert(ret.end(), vp[i].second, vp[i].first);
        }

        return ret;
    }
};
