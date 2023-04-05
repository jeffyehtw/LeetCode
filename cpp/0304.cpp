class NumMatrix {
private:
    vector<vector<int>> preset;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        preset = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));

        preset[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++) {
            preset[i][0] = preset[i - 1][0] + matrix[i][0];
        }
        for (int i = 1; i < n; i++) {
            preset[0][i] = preset[0][i - 1] + matrix[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                preset[i][j] += preset[i - 1][j];
                preset[i][j] += preset[i][j - 1];
                preset[i][j] += matrix[i][j];
                preset[i][j] -= preset[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;

        ret += preset[row2][col2];
        if ((row1 > 0) && (col1 > 0)) {
            ret -= preset[row1 - 1][col2];
            ret -= preset[row2][col1 - 1];
            ret += preset[row1 - 1][col1 - 1];
        } else {
            ret -= (row1 > 0) ? preset[row1 - 1][col2] : 0;
            ret -= (col1 > 0) ? preset[row2][col1 - 1] : 0;
        }
        
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
