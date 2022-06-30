class Solution {
public:
    bool isPerfectSquare(int num) {
        // var
        int left = 1;
        int right = num / 2;
        
        while (left <= right) {
            // var
            long middle = (right - left) / 2 + left;
            long tmp = middle * middle;
            
            if (tmp == num)
                return true;
            else if (tmp > num)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return false;
    }
};