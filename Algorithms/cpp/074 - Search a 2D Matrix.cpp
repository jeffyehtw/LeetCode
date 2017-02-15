class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // skip
        if (!matrix.size() || !matrix[0].size())
            return false;
        
        // var
        int result = -1;
        int n = matrix.size();
        
        // run
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] > target)
                return binary_search(matrix[i - 1], target) > -1;
        }
        return binary_search(matrix[n - 1], target) > -1;
    }
    
    int binary_search(vector<int> matrix, int target) {
        // var
        int mid;
        int left = 0;
        int right = matrix.size() - 1;
        
        while (left <= right) {
            // var
            mid = (left + right) / 2;
            
            if (matrix[mid] == target)
                return mid;
            else if (matrix[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};