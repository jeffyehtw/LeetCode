class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        vector<int> ret;
        int i = 0;
        int j = 0;
        /* 0: >, 1: v, 2: <, 3: ^ */
        int dir = 0;
        
        while (ret.size() < m * n) {
            seen[i][j] = true;
            ret.push_back(matrix[i][j]);
            
            if (dir == 0) {
                if ((j + 1 < n) && !seen[i][j + 1]) {
                    j++;
                } else {
                    dir = 1;
                    i++;
                }
            } else if (dir == 1) {
                if ((i + 1 < m) && !seen[i + 1][j]) {
                    i++;
                } else {
                    dir = 2;
                    j--;
                }
            } else if (dir == 2) {
                if ((j - 1 > -1) && !seen[i][j - 1]) {
                    j--;
                } else {
                    dir = 3;
                    i--;
                }
            } else if (dir == 3) {
                if ((i - 1 > -1) && !seen[i - 1][j]) {
                    i--;
                } else {
                    dir = 0;
                    j++;
                }
            }
        }

        return ret;
    }
};
