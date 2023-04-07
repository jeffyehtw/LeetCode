class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> row(10, false);
            vector<bool> col(10, false);
            
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    if (col[board[i][j] - '0'] == true) {
                        return false;
                    } else {
                        col[board[i][j] - '0'] = true;
                    }
                }
                if (isdigit(board[j][i])) {
                    if (row[board[j][i] - '0'] == true) {
                        return false;
                    } else {
                        row[board[j][i] - '0'] = true;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> cub(10, false);

                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        cout << i + k << " " << j + l << endl;
                        if (!isdigit(board[i + k][j + l])) {
                            continue;
                        }
                        if (cub[board[i + k][j + l] - '0'] == true) {
                            return false;
                        } else {
                            cub[board[i + k][j + l] - '0'] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};
