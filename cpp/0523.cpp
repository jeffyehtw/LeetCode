class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int presum;
        unordered_map<int, int> umap;

        presum = nums[0];
        umap[nums[0] % k] = 0;
        for (int i = 1; i < nums.size(); i++) {
            presum = (presum + nums[i]) % k;

            if (presum == 0) {
                return true;
            } else if (umap.find(presum) != umap.end()) {
                if (i - umap[presum] > 1) {
                    return true;
                }
            } else {
                umap[presum] = i;
            }
        }

        return false;
    }
};
