class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> acc = vector<int>(nums.begin(), nums.end());

        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        } else if (n == 3) {
            return max(nums[1], nums[0] + nums[2]);
        }

        acc[2] += acc[0];
        for (int i = 3; i < n; i++) {
            acc[i] += max(acc[i - 2], acc[i - 3]);
        }

        return max(acc[n - 1], acc[n - 2]);
    }
};
