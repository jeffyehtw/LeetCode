class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, bool> umap;

        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            int left = nums[i] - 1;
            int right = nums[i] + 1;

            while (umap.find(left) != umap.end()) {
                umap.erase(left);
                left--;
            }
            while (umap.find(right) != umap.end()) {
                umap.erase(right);
                right++;
            }
            ret = max(ret, (right - 1) - (left + 1) + 1);
        }
        
        return ret;
    }
};
