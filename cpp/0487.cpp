class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ret = 0;
        int zero = -1;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                if (zero == -1) {
                    zero = right;
                } else {
                    left = zero + 1;
                    zero = right;
                }
            }
            ret = max(ret, right - left + 1);
            right++;
        }

        return ret;
    }
};
