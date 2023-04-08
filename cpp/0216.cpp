class Solution {
private:
    vector<vector<int>> ret;
    void backtrack(vector<int> nums, int idx, int k, int n) {
        if (n == 0) {
            if (nums.size() == k) {
                ret.push_back(nums);
            } 
            return;
        } else if ((idx > n) || (nums.size() > k) || (idx > 9)) {
            return;
        }

        backtrack(nums, idx + 1, k, n);
        nums.push_back(idx);
        backtrack(nums, idx + 1, k, n - idx);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        vector<int> nums;

        if ((n < (1 + k) * k / 2) 
            || (n > (19 - k) * k / 2)) {
            return ret;
        }

        backtrack(nums, 1, k, n);

        return ret;
    }
};
