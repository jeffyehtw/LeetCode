class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // var
        int i = 0;
        int j = 0;
        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        int direction = 0;
        
        // init
        vector<vector<int>> r(n, vector<int>(n, 0));
        
        for (int k = 1; k <= n * n; k++) {
            r[i][j] = k;
            switch(direction) {
                // right
                case 0:
                    if (j < right)
                        j++;
                    else {
                        up++;
                        i++;
                        direction = 1;
                    }
                    break;
                // down
                case 1:
                    if (i < down)
                        i++;
                    else {
                        right--;
                        j--;
                        direction = 2;
                    }
                    break;
                // left
                case 2:
                    if (j > left)
                        j--;
                    else {
                        down--;
                        i--;
                        direction = 3;
                    }
                    break;
                // up
                case 3:
                    if (i > up)
                        i--;
                    else {
                        left++;
                        j++;
                        direction = 0;
                    }
                    break;
            }
        }
        return r;
    }
};