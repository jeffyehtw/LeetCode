class Solution {
private:
    int binary(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] > target) {
                break;
            } else if (matrix[i].back() < target) {
                continue;
            } else {
                if (binary(matrix[i], target) > -1) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
