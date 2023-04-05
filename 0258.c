int addbydigit(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int addDigits(int num) {
    int sum;
    
    if (num < 10) {
        return num;
    }
    
    while (num >= 10) {
        num = addbydigit(num);
    }
    
    return num;
}