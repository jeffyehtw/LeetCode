class Solution {
private:
    vector<vector<int>> ret;
    vector<bool> used;
    vector<int> arr;
    void backtrack(vector<int>& nums) {
        if (arr.size() == nums.size()) {
            ret.push_back(arr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            if ((i > 0) && (nums[i] == nums[i - 1]) && !used[i - 1]) {
                continue;
            }
            arr.push_back(nums[i]);
            used[i] = true;
            backtrack(nums);
            used[i] = false;
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp;
        
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums);

        return ret;
    }
};
