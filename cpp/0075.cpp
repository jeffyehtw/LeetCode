class Solution {
public:
    void sortColors(vector<int>& nums) {
        int min;
        int idx;

        for (int i = 0; i < nums.size(); i++) {
            min = nums[i];
            idx = i;

            for (int j = i + 1; j < nums.size(); j++) {
                if (min > nums[j]) {
                    min = nums[j];
                    idx = j;
                }
            }

            swap(nums[i], nums[idx]);
        }
    }
};
