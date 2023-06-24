class Solution {
private:
    vector<vector<int>> nexts = {
        { -1, 0 },
        { 0, -1 },
        { 0, 1 },
        { 1, 0 },
    };
    void add(vector<int>& a, vector<int>& b, vector<int>& c) {
        c[0] = a[0] + b[0];
        c[1] = a[1] + b[1];
    }
    bool valid(int m, int n, vector<int>& next) {
        return (((next[0] >= 0) && (next[0] < m))
            && ((next[1] >= 0) && (next[1] < n)));
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int step = 0;
        vector<int> cur(2, 0);
        vector<int> next(2, 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ret(m, vector<int>(n, 0));
        queue<vector<int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({ i, j });
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                cur = q.front();
                if (mat[cur[0]][cur[1]] == 1) {
                    ret[cur[0]][cur[1]] = step;
                }
                for (int j = 0; j < nexts.size(); j++) {
                    add(cur, nexts[j], next);
                    if (!valid(m, n, next)) {
                        continue;
                    } else if (visited[next[0]][next[1]]) {
                        continue;
                    }
                    q.push(next);
                    visited[next[0]][next[1]] = true;
                }
                q.pop();
            }
            step++;
        }

        return ret;
    }
};
