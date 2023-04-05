class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 1;

        while ((i < nums.size()) && (j < nums.size())) {
            if (nums[i] == 0) {
                while ((j < nums.size()) && (nums[j] == 0)) {
                    j++;
                }
                if (j < nums.size()) {
                    swap(nums[i], nums[j]);
                }
                i++;
                j++;
            } else {
                i++;
                if (i == j) {
                    j = i + 1;
                }
            }
        }
    }
};
