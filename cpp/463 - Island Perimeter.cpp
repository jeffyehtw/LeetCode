class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        // var
        int result = 0;
        int n = grid.size();
        int m = grid[0].size();

        // run
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j])
                    continue;
                result += i > 0 ? !grid[i - 1][j] : 1;
                result += i < n - 1 ? !grid[i + 1][j] : 1;
                result += j > 0 ? !grid[i][j - 1] : 1;
                result += j < m - 1 ? !grid[i][j + 1] : 1;
            }
        }
        return result;
    }
};