class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        int j = nums.size() - 1;

        if (nums.size() <= 1) {
            return;
        }

        for (; i > -1; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            } else if (i == 0) {
                reverse(nums.begin(), nums.end());
                return;
            }
        }
        for (; j > -1; j--) {
            if (nums[i] < nums[j]) {
                break;
            }
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
