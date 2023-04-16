class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        int all = 1;
        int zero = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero++;
            } else {
                all *= nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ret[i] = (zero > 1) ? 0 : all;
            } else {
                ret[i] = (zero > 0) ? 0 : all / nums[i];
            }
        }

        return ret;
    }
};
