class Solution {
private:
    vector<int> cur;
    vector<vector<int>> ret;
    vector<bool> used;
    void backtrack(vector<int>& num, int idx) {
        if (idx == num.size()) {
            ret.push_back(cur);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (used[i]) {
                continue;
            }
            cur.push_back(num[i]);
            used[i] = true;
            backtrack(num, idx + 1);
            used[i] = false;
            cur.pop_back();
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
