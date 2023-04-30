class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int target = -x;
        int ret = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            target += nums[i];
        }

        if (target == 0) {
            return nums.size();
        }

        while (right < nums.size()) {
            sum += nums[right];

            while ((left < right) && (sum > target)) {
                sum -= nums[left];
                left++;
            }
            if (sum == target) {
                ret = max(ret, right - left + 1);
            }

            right++;
        }

        return (ret == INT_MIN) ? -1 : (nums.size() - ret);
    }
};
