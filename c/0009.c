bool isPalindrome(int x){
    int size = 0;
    int digit[40] = { 0 };
    
    if (x < 0) {
        return false;
    }
    
    while (x > 0) {
        digit[size] = x % 10;
        x /= 10;
        size++;
    }
    
    for (int i = 0; i < size / 2; i++) {
        if (digit[i] != digit[size - 1 - i]) {
            return false;
        }
    }
    return true;
}