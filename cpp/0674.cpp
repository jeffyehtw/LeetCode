class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ret = 1;
        int len = 1;

        if (nums.size() == 1) {
            return ret;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
            } else {
                len = 1;
            }
            ret = max(ret, len);
        }

        return ret;
    }
};
