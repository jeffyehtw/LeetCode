class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        int step = 0;
        queue<vector<int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({ i, j });
                } else if (rooms[i][j] == -1) {
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                vector<int> cur = q.front();

                if (((cur[0] < 0) || (cur[0] >= m))
                    || ((cur[1] < 0) || (cur[1] >= n))) {
                    q.pop();
                    continue;
                } else if (visited[cur[0]][cur[1]]) {
                    q.pop();
                    continue;
                }
                visited[cur[0]][cur[1]] = true;
                rooms[cur[0]][cur[1]] = step;
                q.push({ cur[0] - 1, cur[1] });
                q.push({ cur[0], cur[1] - 1 });
                q.push({ cur[0], cur[1] + 1 });
                q.push({ cur[0] + 1, cur[1] });
                q.pop();
            }
            step++;
        }
    }
};
