class Solution {
private:
    int ret = 0;
    vector<bool> used;
    void _xor(vector<int>& nums) {
        int val = 0;

        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) {
                continue;
            }
            val ^= nums[i];
        }
        ret += val;
    }
    void backtrack(vector<int>& nums, int idx) {
        _xor(nums);
        if (idx >= nums.size()) {
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            used[i] = true;
            backtrack(nums, i + 1);
            used[i] = false;
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        used = vector<bool>(n, false);
        backtrack(nums, 0);

        return ret;
    }
};
