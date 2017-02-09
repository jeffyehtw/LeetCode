class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // var
        int sum = 0;
        int max_sum = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            max_sum = max(sum, max_sum);
            sum = sum < 0 ? 0 : sum;
        }
        return max_sum;
    }
};