class Solution {
private:
    int m;
    int n;
    vector<vector<bool>> visited;
    void traverse(vector<vector<int>>& grid, int i, int j) {
        if ((i < 0) || (i >= m) || (j < 0) || (j >= n)) {
            return;
        } else if (visited[i][j]) {
            return;
        } else if (grid[i][j] == 1) {
            visited[i][j] = true;
            return;
        }
        visited[i][j] = true;
        traverse(grid, i - 1, j);
        traverse(grid, i, j - 1);
        traverse(grid, i, j + 1);
        traverse(grid, i + 1, j);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ret = 0;

        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            if (!visited[i][0]) {
                traverse(grid, i, 0);
            }
            if (!visited[i][n - 1]) {
                traverse(grid, i, n - 1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (!visited[0][j]) {
                traverse(grid, 0, j);
            }
            if (!visited[m - 1][j]) {
                traverse(grid, m - 1, j);
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (visited[i][j]) {
                    continue;
                } else if (grid[i][j] == 1) {
                    visited[i][j] = true;
                    continue;
                } else {
                    ret++;
                    traverse(grid, i, j);
                }
            }
        }

        return ret;
    }
};
