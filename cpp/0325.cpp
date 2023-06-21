class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ret = 0;
        long long cur = 0;
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (cur == k) {
                ret = i + 1;
            } else if (umap.find(cur - k) != umap.end()) {
                ret = max(ret, i - umap[cur - k]);
            }
            if (umap.find(cur) == umap.end()) {
                umap[cur] = i;
            }
        }

        return ret;
    }
};
