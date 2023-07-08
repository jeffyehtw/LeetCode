class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> ret;
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = 1;
            } else {
                umap[nums[i]]++;
            }
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            if (moveFrom[i] == moveTo[i]) {
                continue;
            } else if (umap.find(moveTo[i]) == umap.end()) {
                umap[moveTo[i]] = umap[moveFrom[i]];
            } else {
                umap[moveTo[i]] += umap[moveFrom[i]];
            }
            umap.erase(moveFrom[i]);
        }
        
        for (auto it = umap.begin(); it != umap.end(); it++) {
            ret.push_back(it->first);
        }
        sort(ret.begin(), ret.end());
        
        return ret;
    }
};
