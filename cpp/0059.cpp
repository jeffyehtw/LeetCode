class Solution {
private:
    int x = 0;
    int y = -1;
    int idx = 1;
    void up(vector<vector<int>>& m) {
        x--;
        while ((x > -1) && (m[x][y] == 0)) {
            m[x][y] = idx;
            x--;
            idx++;
        }
        x++;
    }
    void down(vector<vector<int>>& m) {
        x++;
        while ((x < m.size()) && (m[x][y] == 0)) {
            m[x][y] = idx;
            x++;
            idx++;
        }
        x--;
    }
    void left(vector<vector<int>>& m) {
        y--;
        while ((y > -1) && (m[x][y] == 0)) {
            m[x][y] = idx;
            y--;
            idx++;
        }
        y++;
    }
    void right(vector<vector<int>>& m) {
        y++;
        while ((y < m[0].size()) && (m[x][y] == 0)) {
            m[x][y] = idx;
            y++;
            idx++;
        }
        y--;
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));

        while (idx <= n * n) {
            right(ret);
            down(ret);
            left(ret);
            up(ret);
        }

        return ret;
    }
};
