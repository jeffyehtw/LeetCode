class Solution {
private:
    vector<vector<bool>> seen;
    bool help(vector<vector<char>>& b, string s, int idx, int i, int j) {
        int m = b.size();
        int n = b[0].size();

        if (idx >= s.length()) {
            return true;
        } else if ((i < 0) || (i >= m)) {
            return false;
        } else if ((j < 0) || (j >= n)) {
             return false;
        } else if (seen[i][j] || (b[i][j] != s[idx])) {
            return false;
        }

        seen[i][j] = true;
        if (help(b, s, idx + 1, i - 1, j)) {
            return true;
        } else if (help(b, s, idx + 1, i + 1, j)) {
            return true;
        } else if (help(b, s, idx + 1, i, j - 1)) {
            return true;
        } else if (help(b, s, idx + 1, i, j + 1)) {
            return true;
        }
        seen[i][j] = false;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ret = false;
        int m = board.size();
        int n = board[0].size();

        seen = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; (i < m) && !ret; i++) {
            for (int j = 0; (j < n) && !ret; j++) {
                if (board[i][j] == word[0]) {
                    ret |= help(board, word, 0, i, j);
                }
            }
        }

        return ret;
    }
};
