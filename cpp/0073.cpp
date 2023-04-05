class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // var
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> backup(matrix);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (backup[i][j] == 0) {
                    // horizon
                    matrix[i] = vector<int>(m, 0);
                    
                    // vertical
                    for (int k = 0; k < n; k++)
                        matrix[k][j] = 0;
                }
            }
        }
    }
};