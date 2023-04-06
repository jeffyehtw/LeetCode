class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> flat;
        vector<vector<int>> ret;

        if (((m == r) && (n == c))
            || (m * n != r * c)) {
            return mat;
        }

        for (int i = 0; i < m; i++) {
            flat.insert(flat.end(), mat[i].begin(), mat[i].end());
        }

        for (int i = 0; i < r; i++) {
            ret.push_back(vector<int>(
                flat.begin() + (i * c), 
                flat.begin() + (i + 1) * c
            ));
        }

        return ret;
    }
};
