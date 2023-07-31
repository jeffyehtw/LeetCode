class Solution {
private:
    int total;
    vector<int> _w;
public:
    Solution(vector<int>& w) {
        total = 0;
        _w = w;
        for (int i = 0; i < w.size(); i++) {
            total += w[i];
        }
    }
    
    int pickIndex() {
        int idx = rand() % total + 1;

        for (int i = 0; i < _w.size(); i++) {
            if (idx <= _w[i]) {
                return i;
            }
            idx -= _w[i];
        }

        return _w.size() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
