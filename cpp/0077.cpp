class Solution {
private:
    vector<vector<int>> ret;
    vector<int> cur;
    void backtrack(vector<int>& nums, int idx, int k) {
        if (cur.size() == k) {
            ret.push_back(cur);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, k);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        backtrack(nums, 0, k);

        return ret;
    }
};
