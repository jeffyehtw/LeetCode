class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int cnt = 0;
        int ret = -1;
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                continue;
            }
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = 0;
            }
            umap[nums[i]]++;

            if (umap[nums[i]] > cnt) {
                cnt = umap[nums[i]];
                ret = nums[i];
            } else if (umap[nums[i]] == cnt && nums[i] < ret) {
                ret = nums[i];
            }
        }

        return ret;
    }
};
