class Solution {
private:
    vector<vector<int>> ret;
    void backtrack(vector<int>& c, int idx, vector<int> arr, int t) {
        if (t == 0) {
            ret.push_back(arr);
            return;
        } else if ((t < 0) || (idx > c.size() - 1)) {
            return;
        }

        backtrack(c, idx + 1, arr, t);
        while (t >= c[idx]) {
            t -= c[idx];
            arr.push_back(c[idx]);
            backtrack(c, idx + 1, arr, t);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        backtrack(candidates, 0, tmp, target);
        return ret;
    }
};
