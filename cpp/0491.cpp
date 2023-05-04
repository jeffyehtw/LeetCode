class Solution {
private:
    set<vector<int>> ret;
    vector<int> cur;
    vector<bool> used;
    void backtrack(vector<int>& nums, int idx) {
        if (cur.size() >= 2) {
            ret.insert(cur);
        }

        for (int i = idx; i < nums.size(); i++) {
            if ((cur.size() > 0) && (cur.back() > nums[i])) {
                continue;
            }
            if ((i > 0) && (nums[i - 1] == nums[i]) && !used[i - 1]) {
                continue;
            }
            cur.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, i + 1);
            used[i] = false;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        backtrack(nums, 0);
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};
