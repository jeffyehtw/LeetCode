class Solution {
private:
    vector<vector<bool>> seen;
    void explore(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();

        if ((x < 0) || (x >= m) || (y < 0) || (y >= n)) {
            return;
        }
        if ((grid[x][y] == '0') 
            || (grid[x][y] == '1') && (seen[x][y])) {
            return;
        }
        seen[x][y] = true;
        explore(grid, x - 1, y);
        explore(grid, x + 1, y);
        explore(grid, x, y - 1);
        explore(grid, x, y + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        int m = grid.size();
        int n = grid[0].size();

        seen = vector(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (seen[i][j] || (grid[i][j] == '0')) {
                    continue;
                }
                ret++;
                explore(grid, i, j);
            }
        }
        
        return ret;
    }
};
