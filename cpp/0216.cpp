class Solution {
private:
    vector<vector<int>> ret;
    vector<int> cur;
    void backtrack(int idx, int k, int n) {
        if ((cur.size() == k) && (n == 0)) {
            ret.push_back(cur);
            return;
        } else if ((cur.size() > k) || (n < 0)) {
            return;
        }

        for (int i = idx; i <= 9; i++) {
            cur.push_back(i);
            backtrack(i + 1, k, n - i);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, k, n);
        return ret;
    }
};
