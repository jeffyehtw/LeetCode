class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return vector<int>();
        
        // var
        int x = 0;
        int y = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        bool direction = true;
        vector<int> result;
        
        for (int i = 0; i < m * n; i++) {
            result.push_back(matrix[x][y]);
            
            if (direction) {
                if (x - 1 < 0 && y + 1 > n - 1) {
                    x++;   
                    direction = !direction;
                }
                else if (x - 1 < 0) {
                    y++;
                    direction = !direction;
                }
                else if (y + 1 > n - 1) {
                    x++;
                    direction = !direction;
                }
                else {
                    x--;
                    y++;
                }
            }
            else {
                if (x + 1 > m - 1 && y - 1 < 0) {
                    y++;
                    direction = !direction;
                }
                else if (y - 1 < 0) {
                    x++;
                    direction = !direction;
                }
                else if (x + 1 > m - 1) {
                    y++;
                    direction = !direction;
                }
                else {
                    x++;
                    y--;
                }
            }
        }
        return result;
    }
};