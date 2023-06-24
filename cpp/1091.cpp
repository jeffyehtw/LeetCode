class Solution {
private:
    vector<vector<int>> nexts = {
        { -1, -1 },
        { -1, 0 },
        { -1, 1 },
        { 0, -1 },
        { 0, 1 },
        { 1, -1 },
        { 1, 0 },
        { 1, 1 }
    };
    string key(vector<int> val) {
        return to_string(val[0]) + "," + to_string(val[1]);
    }
    void add(vector<int>& a, vector<int>& b, vector<int>& c) {
        c[0] = a[0] + b[0];
        c[1] = a[1] + b[1];
    }
    bool valid(int m, int n, vector<int>& next) {
        return (((next[0] >= 0) && (next[0] < m))
            && ((next[1] >= 0) && (next[1] < n)));
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int step = 1;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> cur(2, 0);
        vector<int> next(2, 0);
        queue<vector<int>> q;

        if ((grid[0][0] == 1) || (grid[m - 1][n - 1] == 1)) {
            return -1;
        }
        visited[0][0] = true;

        q.push(cur);
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                cur = q.front();

                if ((cur[0] == m - 1) && (cur[1] == n - 1)) {
                    return step;
                } else if (grid[cur[0]][cur[1]] == 1) {
                    q.pop();
                    continue;
                }
                
                for (int j = 0; j < nexts.size(); j++) {
                    add(cur, nexts[j], next);
                    if (!valid(m, n, next) 
                        || (visited[next[0]][next[1]])) {
                        continue;
                    }
                    q.push(next);
                    visited[next[0]][next[1]] = true;
                }
                q.pop();
            }
            step++;
        }

        return -1;
    }
};
