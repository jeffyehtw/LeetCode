class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
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
            vp.push_back(pair<int, int>(make_pair(it->first, it->second)));
        }
        sort(vp.begin(), vp.end(), [](pair<int, int> p, pair<int, int> q) {
            return p.second > q.second;
        });
        for (int i = 0; i < k; i++) {
            ret.push_back(vp[i].first);
        }

        return ret;
    }
};
