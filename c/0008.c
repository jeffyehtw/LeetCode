bool issign(char c) {
    return (c == '+' || c == '-');
}

int myAtoi(char * s) {
    int index = 0;
    int n = strlen(s);
    bool positive = true;
    long long ret = 0;
    
    while (s[index] == ' ') {
        index++;
    }
    
    if (s[index] == '+') {
        positive = true;
        index++;
    }
    else if (s[index] == '-') {
        positive = false;
        index++;
    }
    
    while (index < n) {
        if (isdigit(s[index])) {
            ret *= 10;
            ret += s[index] - '0';
        }
        else {
            break;
        }
        if (ret > (long long)INT_MAX + (positive ? 0 : 1)) {
            ret = positive ? INT_MAX : INT_MAX + 1;
            break;
        }
        index++;
    }
    
    return positive ? ret : -1 * ret;
}