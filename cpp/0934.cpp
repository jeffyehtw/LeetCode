class Solution {
private:
    int m;
    int n;
    vector<vector<bool>> visited;
    queue<vector<int>> q;
    bool valid(int x, int y) {
        return !((x < 0) || (x >= m) || (y < 0) || (y >= n));
    }
    void traverse(vector<vector<int>>& g, int x, int y) {
        if ((x < 0) || (x >= m) || (y < 0) || (y >= n)) {
            return;
        } else if (visited[x][y]) {
            return;
        } else if (g[x][y] == 0) {
            visited[x][y] = true;
            q.push({ x, y });
            return;
        }
        visited[x][y] = true;
        traverse(g, x - 1, y);
        traverse(g, x, y - 1);
        traverse(g, x, y + 1);
        traverse(g, x + 1, y);
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int ret = 0;

        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; (i < m) && q.empty(); i++) {
            for (int j = 0; (j < n) && q.empty(); j++) {
                if (grid[i][j] == 1) {
                    traverse(grid, i, j);
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                vector<int> cur = q.front();

                if (!valid(cur[0], cur[1])) {
                    q.pop();
                    continue;
                } else if ((ret > 0) && visited[cur[0]][cur[1]]) {
                    q.pop();
                    continue;
                } else if (grid[cur[0]][cur[1]] == 1) {
                    return ret;
                }

                visited[cur[0]][cur[1]] = true;
                q.push({ cur[0] - 1, cur[1] });
                q.push({ cur[0], cur[1] - 1 });
                q.push({ cur[0], cur[1] + 1 });
                q.push({ cur[0] + 1, cur[1] });
                q.pop();
            }
            ret++;
        }

        return 0;      
    }
};
