class Solution {
    vector<vector<int>> ret;
    void _combine(vector<int> nums, int idx, int n, int k) {
        if (k == 0) {
            ret.push_back(nums);
            return;
        } else if (idx > n || n - idx + 1 < k) {
            return;
        }
        
        _combine(nums, idx + 1, n, k);
        nums.push_back(idx);
        _combine(nums, idx + 1, n, k - 1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        _combine(tmp, 1, n, k);
        return ret;
    }
};
