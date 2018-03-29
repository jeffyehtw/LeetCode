class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        // var
        int r = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> tagged;
        
        // init
        tagged = vector<vector<bool>>(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 || tagged[i][j])
                    continue;
                
                r = max(r, discover(i, j, grid, tagged));
            }
        }
        
        return r;
    }
    
    int discover(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& tagged) {
        // var
        int r = 1;
        
        tagged[x][y] = true;
        
        if (x > 0 && !tagged[x - 1][y] && grid[x - 1][y] == 1)
            r += discover(x - 1, y, grid, tagged);
        if (x < grid.size() - 1 && !tagged[x + 1][y] && grid[x + 1][y] == 1)
            r += discover(x + 1, y, grid, tagged);
        if (y > 0 && !tagged[x][y - 1] && grid[x][y - 1] == 1)
            r += discover(x, y - 1, grid, tagged);
        if (y < grid[0].size() - 1 && !tagged[x][y + 1] && grid[x][y + 1] == 1)
            r += discover(x, y + 1, grid, tagged);
        
        return r;
    }
};
