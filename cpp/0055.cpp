class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> valid(n, false);

        valid[0] = true;
        for (int i = 0; i < n; i++) {
            if (valid[i] == false) {
                return false;
            }
            if ((i + nums[i]) >= (n - 1)) {
                return true;
            }
            for (int j = 1; (j <= nums[i]) && (i + j < n); j++) {
                valid[i + j] = true;
            }
        }

        return true;
    }
};
