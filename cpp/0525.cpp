class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt;
        int ret = 0;
        unordered_map<int, int> umap;

        cnt = (nums[0] == 1) ? 1 : -1;
        umap[cnt] = 0;
        for (int i = 1; i < nums.size(); i++) {
            cnt += (nums[i] == 1) ? 1 : -1;

            if (cnt == 0) {
                ret = max(ret, i + 1);
            } else if (umap.find(cnt) != umap.end()) {
                if (i - umap[cnt] > 1) {
                    ret = max(ret, i - umap[cnt]);
                }
            } else {
                umap[cnt] = i;
            }
        }

        return ret;
    }
};
