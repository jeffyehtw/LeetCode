class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ret = 0;

        if (nums.size() < 3) {
            return ret;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            int val = target - nums[i];

            while (left < right) {
                if (nums[left] + nums[right] >= val) {
                    right--;
                } else {
                    ret += right - left;
                    left++;
                }
            }
        }

        return ret;
    }
};
