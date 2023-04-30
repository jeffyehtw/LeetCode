class Solution {
private:
    int left(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                right = mid - 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if ((left == nums.size()) || (nums[left] != target)) {
            return -1;
        } else {
            return left;
        }
    }
    int right(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if ((right < 0) || (nums[right] != target)) {
            return -1;
        } else {
            return right;
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>({
            left(nums, target),
            right(nums, target)
        });
    }
};
