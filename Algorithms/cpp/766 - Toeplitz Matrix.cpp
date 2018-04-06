class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // var
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m && i + j < n; j++)
                if (matrix[i][0] != matrix[i + j][j])
                    return false;
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n && i + j < m; j++)
                if (matrix[0][i] != matrix[j][i + j])
                    return false;
        
        return true;
    }
};
