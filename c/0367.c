bool isPerfectSquare(int num) {
    unsigned long left = 0;
    unsigned long right = num;
    unsigned long middle;
    
    while (left <= right) {
        middle = (left + right) >> 1;
        
        if (middle * middle == num) {
            return true;
        }
        else if (middle * middle > num) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    
    return false;
}