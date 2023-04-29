class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ret(mat.begin(), mat.end());

        for (int i = 1; i < m; i++) {
            mat[i][0] += mat[i - 1][0];
        }
        for (int i = 1; i < n; i++) {
            mat[0][i] += mat[0][i - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1];
                mat[i][j] -= mat[i - 1][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = min(i + k, m - 1);
                int y1 = min(j + k, n - 1);
                int x2 = i - k - 1;
                int y2 = j - k - 1;

                ret[i][j] = mat[x1][y1];
                if (x2 >= 0) {
                    ret[i][j] -= mat[x2][y1];
                }
                if (y2 >= 0) {
                    ret[i][j] -= mat[x1][y2];
                }
                if ((x2 >= 0) && (y2 >= 0)) {
                    ret[i][j] += mat[x2][y2];
                }
            }
        }

        return ret;
    }
};
