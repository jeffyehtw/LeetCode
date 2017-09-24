class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        helper(nums, 0, S);
        return result;
    }
private:
    // var
    int result = 0;
    
    void helper(vector<int>& nums, int start, int S) {
        if (start == nums.size()) {
            if (S == 0)
                ++result;
            return;
        }
        helper(nums, start + 1, S + nums[start]);
        helper(nums, start + 1, S - nums[start]);
    }
};