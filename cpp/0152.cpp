class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret;
        vector<int> dpmin(nums.size(), 0);
        vector<int> dpmax(nums.size(), 0);

        dpmin[0] = nums[0];
        dpmax[0] = nums[0];
        ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dpmin[i] = min({
                nums[i],
                dpmin[i - 1] * nums[i],
                dpmax[i - 1] * nums[i]
            });
            dpmax[i] = max({
                nums[i],
                dpmin[i - 1] * nums[i],
                dpmax[i - 1] * nums[i]
            });
            ret = max(ret, dpmax[i]);
        }

        return ret;
    }
};
