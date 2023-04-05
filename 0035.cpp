class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 1;
        int right = nums.size() - 1;

        if (target <= nums[0]) {
            return 0;
        } else if (target > nums[nums.size() - 1]) {
            return nums.size();
        }

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
