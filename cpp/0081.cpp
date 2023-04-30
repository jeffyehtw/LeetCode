class Solution {
private:
    bool binary(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int max = nums[0];
        int idx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                idx = i - 1;
                max = nums[i - 1];
            }
        }

        if (idx == nums.size() - 1) {
            return binary(nums, 0, idx, target);
        }

        if (((target >= nums[0]) && (target <= max))
            && binary(nums, 0, idx, target)) {
            return true;
        } else if ((target >= nums[idx + 1] && (target <= nums.back()))
            && binary(nums, idx + 1, nums.size() - 1, target)) {
            return true;
        }

        return false;
    }
};
