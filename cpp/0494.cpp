class Solution {
private:
    int ret = 0;
    void helper(vector<int>& nums, int idx, int target) {
        if (idx == nums.size()) {
            if (target == 0) {
                ret++;
            }
            return;
        }

        helper(nums, idx + 1, target - nums[idx]);
        helper(nums, idx + 1, target + nums[idx]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums, 0, target);
        return ret;
    }
};
