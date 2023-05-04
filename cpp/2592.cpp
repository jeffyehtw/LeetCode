class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int ret = 0;
        int left = 0;
        int right = nums.size() - 1;

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[left] > nums[i]) {
                ret++;
                left++;
            } else {
                right++;
            }
        }

        return ret;
    }
};
