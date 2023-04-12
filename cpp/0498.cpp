class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ret;
        int m = mat.size();
        int n = mat[0].size();
        int x;
        int y;
        
        for (int i = 1; i <= max(m, n) * 2; i++) {
            if (i % 2 == 0) {
                x = 0;
                y = i - 1;
            } else {
                x = i - 1;
                y = 0;
            }
            while ((x > -1) && (y > -1)) {
                if ((x < m) && (y < n)) {
                    ret.push_back(mat[x][y]);
                }
                if (i % 2 == 0) {
                    x++;
                    y--;
                } else {
                    x--;
                    y++;
                }
            }
        }
    
        return ret;
    }
};
