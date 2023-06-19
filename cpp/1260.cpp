class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int idx = 0;
        vector<vector<int>> ret(m, vector<int>(n, 0));
        vector<int> flat;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                flat.push_back(grid[i][j]);
            }
        }
        k %= m * n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret[i][j] = flat[(flat.size() - k + idx) % flat.size()];
                idx++;
            }
        }

        return ret;
    }
};
