class Solution {
private:
    int ret = 0;
    int cur = 0;
    int m;
    int n;
    vector<vector<bool>> visited;
    void traverse(vector<vector<int>>& g, int x, int y) {
        if ((x < 0) || (x >= m) || (y < 0) || (y >= n)) {
            return;
        } else if (visited[x][y]) {
            return;
        } else if (g[x][y] == 0) {
            visited[x][y] = true;
            return;
        }
        cur++;
        visited[x][y] = true;
        traverse(g, x - 1, y);
        traverse(g, x, y - 1);
        traverse(g, x, y + 1);
        traverse(g, x + 1, y);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) {
                    continue;
                } else if (grid[i][j] == 0) {
                    visited[i][j] = true;
                } else {
                    cur = 0;
                    traverse(grid, i, j);
                    ret = max(ret, cur);
                }
            }
        }

        return ret;
    }
};
