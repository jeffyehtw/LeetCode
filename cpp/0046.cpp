class Solution {
private:
    vector<vector<int>> ret;
    vector<int> cur;
    vector<bool> used;
    void backtrack(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ret.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            cur.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, idx + 1);
            cur.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ret;
    }
};
