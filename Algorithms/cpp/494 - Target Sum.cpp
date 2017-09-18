class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // var
        int count = 0;
        helper(nums, S, 0, count);
        return count;
    }
    
    void helper(vector<int>& nums, int S, int start, int& count) {
        if (start >= nums.size()) {
            count += S == 0;
            return;
        }
        helper(nums, S + nums[start], start + 1, count);
        helper(nums, S - nums[start], start + 1, count);
    }
};