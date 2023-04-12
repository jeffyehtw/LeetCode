class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ret = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = grid[i].size() - 1; j > -1; j--) {
                if (grid[i][j] < 0) {
                    ret++;
                } else {
                    break;
                }
            }
        }

        return ret;
    }
};
