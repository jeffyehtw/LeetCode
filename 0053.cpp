class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        // var
        int cum = 0;
        int sum = nums[0];
        
        for (auto num : nums) {
            cum += num;
            sum = cum > sum ? cum : sum;
            cum = cum < 0 ? 0 : cum;
        }
        return sum;
    }
};