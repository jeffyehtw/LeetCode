class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ret = 0;

        for (int i = 2; i < nums.size(); i++) {
            int diff = nums[i - 1] - nums[i - 2];

            if (diff != nums[i] - nums[i - 1]) {
                continue;
            }
            ret++;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] - nums[j - 1] == diff) {
                    ret++;
                } else {
                    break;
                }
            }
        }

        return ret;
    }
};
