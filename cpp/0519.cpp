class Solution {
private:
    int _m;
    int _n;
    map<vector<int>, bool> map;
public:
    Solution(int m, int n) {
        _m = m;
        _n = n;
        reset();
    }
    
    vector<int> flip() {
        vector<int> ret;

        if (map.size() == _m * _n) {
            return ret;
        }
        while (true) {
            vector<int> v = { 
                rand() % _m, 
                rand() % _n 
            };
            if (map.find(v) == map.end()) {
                ret = v;
                map[v] = true;
                break;
            } else {
                map[v] = true;
            }
        }

        return ret;
    }
    
    void reset() {
        map.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
