class Solution {
private:
    int m;
    int n;
    unordered_map<string, bool> seen;
    vector<vector<bool>> visited;
    string cur = "";
    void backtrack(vector<vector<int>>& g, int i, int j, string dir) {
        if ((i < 0) || (i >= m)) {
            return;
        } else if ((j < 0) || (j >= n)) {
            return;
        } else if (visited[i][j]) {
            return;
        } else if (g[i][j] == 0) {
            visited[i][j] = true;
            return;
        }
        cur += dir + ",";
        visited[i][j] = true;
        backtrack(g, i - 1, j, "1");
        backtrack(g, i, j - 1, "2");
        backtrack(g, i, j + 1, "3");
        backtrack(g, i + 1, j, "4");
        cur += "-" + dir + ",";
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) {
                    continue;
                } else if (grid[i][j] == 0) {
                    visited[i][j] = true;
                    continue;
                } else if (grid[i][j] == 1) {
                    cur = "";
                    backtrack(grid, i, j, "0");
                    if (seen.find(cur) == seen.end()) {
                        seen[cur] = true;
                    }
                }
            }
        }

        return seen.size();
    }
};
