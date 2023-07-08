class Solution {
private:
    int _m;
    int _n;
    unordered_map<string, int> umap;
    void add(int x, int y) {
        string pos;
        
        if ((x < 0) || (x >= _m - 1)) {
            return;
        } else if ((y < 0) || (y >= _n - 1)) {
            return;
        }
        
        pos = to_string(x) + "," + to_string(y);
        if (umap.find(pos) == umap.end()) {
            umap[pos] = 1;
        } else {
            umap[pos]++;
        }
    }
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        long long count = 0;
        vector<long long> ret(5, 0);
        
        _m = m;
        _n = n;
        for (int i = 0; i < coordinates.size(); i++) {
            add(coordinates[i][0], coordinates[i][1]);
            add(coordinates[i][0] - 1, coordinates[i][1]);
            add(coordinates[i][0], coordinates[i][1] - 1);
            add(coordinates[i][0] - 1, coordinates[i][1] - 1);
        }
        for (auto it = umap.begin(); it != umap.end(); it++) {
            ret[it->second]++;
            count++;
        }
        ret[0] = (long long)(m - 1) * (n - 1) - count;
        
        return ret;
    }
};
