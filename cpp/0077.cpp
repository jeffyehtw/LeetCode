class Solution {
private:
    vector<vector<int>> ret;
    vector<int> cur;
    void backtrack(int n, int k, int idx) {
        if (cur.size() == k) {
            ret.push_back(cur);
            return;
        }
        for (int i = idx; i <= n; i++) {
            cur.push_back(i);
            backtrack(n, k, i + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return ret;
    }
};
