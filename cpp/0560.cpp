class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        int presum = nums[0];
        unordered_map<int, int> umap;

        umap[presum] = 1;
        ret += (presum == k);
        for (int i = 1; i < nums.size(); i++) {
            presum += nums[i];
            if (presum == k) {
                ret++;
            }
            if (umap.find(presum - k) != umap.end()) {
                ret += umap[presum - k];
            }
            if (umap.find(presum) == umap.end()) {
                umap[presum] = 1;
            } else {
                umap[presum]++;
            }
        }

        return ret;
    }
};
