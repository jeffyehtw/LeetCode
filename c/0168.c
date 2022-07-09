char* convertToTitle(int columnNumber) {
    int n = columnNumber;
    int len = 1;
    char* ret = NULL;
    
    while (n > 26) {
        n -= (n % 26) ? (n % 26) : 26;
        n /= 26;
        len++;
    }
        
    ret = malloc((len + 1) * sizeof(char));
    memset(ret, 0, (len + 1) * sizeof(char));
    
    n = columnNumber;
    for (int i = 0; i < len; i++) {
        ret[len - 1 - i] = (n % 26) ? n % 26 + 'A' - 1 : 'Z';
        n -= (n % 26) ? n % 26 : 26;
        n /= 26;
    }
    
    return ret;
}