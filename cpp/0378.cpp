class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        vector<int> idx(m, 0);
        int min;
        int row;

        for (int i = 0; i < k; i++) {
            min = INT_MAX;
            row = -1;

            for (int j = 0; j < m; j++) {
                if ((idx[j] < m) && (min > matrix[j][idx[j]])) {
                    min = matrix[j][idx[j]];
                    row = j;
                }
            }

            idx[row]++;
        }

        return min;
    }
};
