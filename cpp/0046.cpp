class Solution {
private:
    vector<vector<int>> ret;
    void _permute(vector<int>& nums, int n) {
        if (n == nums.size() - 1) {
            ret.push_back(nums);
        }
        for (int i = n; i < nums.size(); i++) {
            swap(nums[n], nums[i]);
            _permute(nums, n + 1);
            swap(nums[n], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        _permute(nums, 0);
        return ret;
    }
};
