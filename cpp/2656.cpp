class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int ret = 0;

        for (int i = 0; i < nums.size(); i++) {
            ret = max(ret, nums[i]);
        }

        return (ret * k) + (1 + k - 1) * (k - 1) / 2;
    }
};
