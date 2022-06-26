int mySqrt(int x){    
    int left = 1;
    int right = x >> 1;
    int middle;
    int remainder;
    
    if (x == 0) {
        return 0;
    }
    else if (x < 4) {
        return 1;
    }
    
    middle = (left + right) >> 1;
    remainder = x / middle;
    
    while (left < right) {        
        if (remainder == middle) {
            break;
        }
        else if (remainder < middle) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
        middle = (left + right) >> 1;
        remainder = x / middle;
    }
    
    return remainder > middle ? middle : remainder;
}