class Solution {
private:
    vector<vector<bool>> visited;
    void traverse(vector<vector<char>>& b, int i, int j) {
        int m = b.size();
        int n = b[0].size();

        if ((i < 0) || (i >= m) || (j < 0) || (j >= n)) {
            return;
        } else if (visited[i][j]) {
            return;
        } else if (b[i][j] == 'X') {
            visited[i][j] = true;
            return;
        }
        visited[i][j] = true;
        traverse(b, i - 1, j);
        traverse(b, i, j - 1);
        traverse(b, i, j + 1);
        traverse(b, i + 1, j);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();        
        vector<vector<int>> edges;

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    visited[i][j] = true;
                } else if ((i == 0) 
                    || (j == 0) 
                    || (i == m - 1) 
                    || (j == n - 1)) {
                    edges.push_back({ i, j });
                }
            }
        }
        for (int i = 0; i < edges.size(); i++) {
            traverse(board, edges[i][0], edges[i][1]);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
