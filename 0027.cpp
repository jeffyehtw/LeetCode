class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;

        if (left > right) {
            return 0;
        }

        while (left < right) {
            while (nums[left] != val && left < right) {
                left++;
            }
            while (nums[right] == val && left < right) {
                right--;
            }

            swap(nums, left, right);
            left++;
            right--;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                return i;
            }
        }
        return nums.size();
    }
};
