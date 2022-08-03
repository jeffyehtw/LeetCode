bool isPowerOfTwo(int n) {
    if (n < 1) {
        return false;
    }
    else if (n == 1) {
        return true;
    }
    
    while (n > 1) {
        if (n & 1 == 1) {
            return false;
        }
        n >>= 1;
    }
    return true;
}