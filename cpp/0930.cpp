class Solution {
private:
    int help(vector<int>& nums, int goal) {
        int left = 0;
        int right = 0;
        int cur = 0;
        int ret = 0;

        if (goal < 0) {
            return 0;
        }

        while (right < nums.size()) {
            cur += (nums[right] == 1);
            while (cur > goal) {
                cur -= (nums[left] == 1);
                left++;
            }
            ret += right - left + 1;
            right++;
        }

        return ret;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return help(nums, goal) - help(nums, goal - 1);
    }
};
