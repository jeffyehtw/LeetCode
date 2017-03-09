class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return vector<int>();
            
        // var
        int x = 0;
        int y = 0;
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        int direction = 0;
        
        vector<int> result;
        
        while (left <= right && up <= down) {
            result.push_back(matrix[x][y]);
            switch(direction) {
                // right
                case 0:
                    if (y < right)
                        y++;
                    else {
                        x++;
                        up++;
                        direction = 1;
                    }
                    break;
                // down
                case 1:
                    if (x < down)
                        x++;
                    else {
                        y--;
                        right--;
                        direction = 2;
                    }
                    break;
                // left
                case 2:
                    if (y > left)
                        y--;
                    else {
                        x--;
                        down--;
                        direction = 3;
                    }
                    break;
                // up
                case 3:
                    if (x > up)
                        x--;
                    else {
                        y++;
                        left++;
                        direction = 0;
                    }
                    break;
            }
        }
        return result;
    }
};