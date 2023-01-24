class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int sum = 0;
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            sum += nums[right];

            while (sum >= target && left <= right) {
                len = min(len, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return len == INT_MAX ? 0 : len;
    }
};