class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int del = -1;
        int left = 0;
        int right = 0;
        int ret = 0;
        int cur = 0;

        while (right < nums.size()) {
            if (nums[right] == 1) {
                cur++;
                if (left == -1) {
                    left = right;
                }
            } else {
                if (del == -1) {
                    del = right;
                } else {
                    left = del + 1;
                    del = right;
                    cur = right - left;
                }
            }
            ret = max(ret, cur);
            right++;
        }

        return (del == -1) ? ret - 1 : ret;
    }
};
