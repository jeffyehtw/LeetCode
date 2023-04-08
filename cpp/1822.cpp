class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ret = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                return 0;
            }
            ret *= (nums[i] > 0) ? 1 : -1;
        }

        return ret;
    }
};
