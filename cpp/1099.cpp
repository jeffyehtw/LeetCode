class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int ret = -1;

        sort(nums.begin(), nums.end());
        while (left < right) {
            if (nums[left] + nums[right] >= k) {
                right--;
            } else {
                ret = max(ret, nums[left] + nums[right]);
                left++;
            }
        }

        return ret;
    }
};
