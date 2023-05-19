class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = true;
            } else {
                return nums[i];
            }
        }

        return -1;
    }
};
