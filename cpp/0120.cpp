class Solution {
private:
    bool valid(vector<vector<int>>& t, int x, int y) {
        if ((x < 0) || (y < 0)) {
            return false;
        } else if (x >= t.size()) {
            return false;
        } else if (y >= t[x].size()) {
            return false;
        }
        return true;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ret = INT_MAX;
        
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int left = INT_MAX;
                int right = INT_MAX;
                
                if (valid(triangle, i - 1, j - 1)) {
                    left = triangle[i - 1][j - 1];
                }
                if (valid(triangle, i - 1, j)) {
                    right = triangle[i - 1][j];
                }
                triangle[i][j] += min(left, right);
            }
        }
        for (int i = 0; i < triangle.back().size(); i++) {
            ret = min(ret, triangle.back()[i]);
        }

        return ret;
    }
};
