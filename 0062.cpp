class Solution {
public:
    int uniquePaths(int m, int n) {
        // var
        vector<vector<int>> v(m, vector<int>(1, 1));
        
        // init
        v[0] = vector<int>(n, 1);
        
        // run
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                v[i].push_back(v[i - 1][j] + v[i][j - 1]);
            }
        }
        
        return v.back().back();
    }
};