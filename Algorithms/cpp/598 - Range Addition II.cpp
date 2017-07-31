class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0)
            return m * n;
        
        // var
        int x = ops[0][0] - 1;
        int y = ops[0][1] - 1;
        
        for (int i = 1; i < ops.size(); i++) {
            x = min(x, ops[i][0] - 1);
            y = min(y, ops[i][1] - 1);
        }
        
        return (x + 1) * (y + 1);
    }
};