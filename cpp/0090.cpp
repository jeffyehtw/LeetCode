class Solution {
private:
    vector<vector<int>> ret;
    vector<int> cur;
    void backtrack(vector<int>& nums, int idx) {
        ret.push_back(cur);

        for (int i = idx; i < nums.size(); i++) {
            if ((i > idx) && (nums[i] == nums[i - 1])) {
                continue;
            }
            cur.push_back(nums[i]);
            backtrack(nums, i + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ret;
    }
};
