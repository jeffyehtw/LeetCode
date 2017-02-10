class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // var
        int n = matrix.size();
        
        // mirro
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i].push_back(matrix[n - 1 - j][n - 1 - i]);
        
        // remove old
        for (int i = 0; i < n; i++)
            matrix[i].assign(matrix[i].begin() + n, matrix[i].end());
        
        // 180
        for (int i = 0; i < n / 2; i++)
            swap(matrix[i], matrix[n - 1 - i]);
    }
};