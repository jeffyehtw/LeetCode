class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = 1;
            } else {
                umap[nums[i]]++;
                if (umap[nums[i]] == 3) {
                    umap.erase(nums[i]);
                }
            }
        }

        return umap.begin()->first;
    }
};
