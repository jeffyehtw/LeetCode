class Solution {
private:
    vector<int> ret;
    void help(int idx, int n) {
        if (idx > n) {
            return;
        }
        ret.push_back(idx);
        for (int i = 0; i <= 9; i++) {
            help(idx * 10 + i, n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            help(i, n);
        }
        return ret;
    }
};
