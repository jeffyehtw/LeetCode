class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = 1;
            } else {
                umap.erase(nums[i]);
            }
        }
        for (auto it = umap.begin(); it != umap.end(); it++) {
            ret.push_back((*it).first);
        }

        return ret;
    }
};
