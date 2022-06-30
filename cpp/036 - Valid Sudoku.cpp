class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // var
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vertical(9, vector<bool>(9, false));
        vector<vector<bool>> horizon(9, vector<bool>(9, false));
        vector<vector<bool>> square(9, vector<bool>(9, false));
        
        // run
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // skip
                if (board[i][j] == '.')
                    continue;
                
                // var
                int index = (i / 3) * 3 + j / 3;
                int num = board[i][j] - '0';
                
                if(vertical[j][num - 1] || horizon[i][num - 1] || square[index][num - 1])
                    return false;
                
                vertical[j][num - 1] = true;
                horizon[i][num - 1] = true;
                square[index][num - 1] = true;
            }
        }
        return true;
    }
};