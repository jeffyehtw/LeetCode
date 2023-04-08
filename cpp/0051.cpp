class Solution {
private:
    vector<vector<string>> ret;
    bool valid(vector<string>& table, int row, int col) {
        int n = table.size();

        for (int i = row - 1; i > -1; i--) {
            if (table[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; (i > -1) && (j < n); i--, j++) {
            if (table[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; (i > -1) && (j > -1); i--, j--) {
            if (table[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
    void backtrack(vector<string>& table, int row) {
        int n = table.size();

        if (row == n) {
            ret.push_back(table);
        } else if (row > n) {
            return;
        }

        for (int i = 0; i < n; i++) {
            if (valid(table, row, i)) {
                table[row][i] = 'Q';
                backtrack(table, row + 1);
                table[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> table(n, string(n, '.'));
        backtrack(table, 0);
        return ret;
    }
};
