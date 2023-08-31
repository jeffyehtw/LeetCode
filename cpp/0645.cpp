class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int all = 0;
        unordered_map<int, int> umap;
        vector<int> ret(2, 0);

        for (int i = 0; i < nums.size(); i++) {
            all ^= nums[i];
            all ^= i + 1;
            if (umap.find(nums[i]) != umap.end()) {
                ret[0] = nums[i];
            } else {
                umap[nums[i]] = i;
            }
        }
        ret[1] = all ^ ret[0];

        return ret;
    }
};
