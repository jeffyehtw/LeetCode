class Solution {
private:
    set<vector<int>> st;
    void _permuteUnique(vector<int>& nums, int n) {
        if (n == nums.size() - 1) {
            st.insert(nums);
        }

        for (int i = n; i < nums.size(); i++) {
            swap(nums[n], nums[i]);
            _permuteUnique(nums, n + 1);
            swap(nums[n], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        _permuteUnique(nums, 0);
        return vector<vector<int>>(st.begin(), st.end());
    }
};
