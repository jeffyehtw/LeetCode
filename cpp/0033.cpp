class Solution {
private:
    int binary(vector<int>& nums, int left, int right, int target) {
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
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int max = nums[0];
        int idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (max < nums[i]) {
                max = nums[i];
                idx = i;
            }
        }

        if ((target > max) 
            || ((idx + 1 < nums.size()) && (target < nums[idx + 1]))) {
            return -1;
        }

        if ((target >= nums[0]) && (target <= max)) {
            return binary(nums, 0, idx, target);
        } else {
            return binary(nums, idx + 1, nums.size() - 1, target);
        }
    }
};
