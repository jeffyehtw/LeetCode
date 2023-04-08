class Solution {
private:
    vector<vector<int>> ret;
    vector<int> arr;
    vector<bool> used;
    void backtrack(vector<int>& c, int t) {
        if (t == 0) {
            ret.push_back(arr);
            return;
        } else if (t < 0) {
            return;
        }

        for (int i = 0; i < c.size(); i++) {
            if (used[i]) {
                continue;
            }
            if ((i > 0) && !used[i - 1] && (c[i] == c[i - 1])) {
                continue;
            }
            if ((arr.size() > 0) && (c[i] < arr.back())) {
                continue;
            }
            arr.push_back(c[i]);
            used[i] = true;
            backtrack(c, t - c[i]);
            used[i] = false;
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        used = vector<bool>(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target);
        return ret;
    }
};
