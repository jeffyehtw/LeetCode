class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        if (nums.size() == 2) {
            return nums[0] > nums[1] ? nums[1] : nums[0];
        }

        while (left < right - 1) {
            int middle = (left + right) / 2;

            if (nums[left] < nums[right]) {
                return nums[left];
            } else if ((nums[middle] < nums[left])
                && (nums[middle] < nums[right])) {
                left++;
                right--;
            } else if (nums[middle] > nums[left]) {
                left = middle;
            } else {
                right = middle;
            }
            //cout << left << " " << right << endl;
        }

        return nums[left] > nums[right] ? nums[right] : nums[left];
    }
};
