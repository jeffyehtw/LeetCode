class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0;
        int ret = 0;
        vector<int> cnts(nums.size(), 0);
        unordered_map<int, int> umap;

        umap[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 1) ? 1 : -1;
            if (cnt == 0) {
                ret = i + 1;
            } else if (umap.find(cnt) == umap.end()) {
                umap[cnt] = i;
            } else {
                ret = max(ret, i - umap[cnt]);
            }
        }

        return ret;
    }
};
