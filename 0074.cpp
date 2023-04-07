class Solution {
private:
    int binary(vector<int>& m, int target) {
        int left = 0;
        int right = m.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (m[mid] == target) {
                return mid;
            } else if (m[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
    int binary2D(vector<vector<int>>& m, int target) {
        int left = 0;
        int right = m.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (m[mid][0] > target) {
                right = mid - 1;
            } else {
                if (m[mid].back() < target) {
                    left = mid + 1;
                } else {
                    return mid;
                }
            }
        }
        
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = binary2D(matrix, target);

        if (i < 0) {
            return false;
        }
        
        return (binary(matrix[i], target) > -1) ? true : false;
    }
};
