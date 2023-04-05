char * maxValue(char * n, int x) {
    bool positive = n[0] == '-' ? false : true;
    unsigned int ret_size = strlen(n) + 1;
    char* ret = malloc((ret_size + 1) * sizeof(char));
    
    memset(ret, 0, (ret_size + 1) * sizeof(char));
    
    if (positive == true) {
        int index = 0;
        for (int i = 0; i < strlen(n); i++, index++) {
            if (x > n[i] - '0') {
                break;
            }
        }
        memcpy(ret, n, index);
        ret[index] = x + '0';
        memcpy(ret + index + 1, n + index, strlen(n) - index);
    }
    else {
        int index = 1;
        for (int i = 1; i < strlen(n); i++, index++) {
            if (x < n[i] - '0') {
                break;
            }
        }
        memcpy(ret, n, index);
        ret[index] = x + '0';
        memcpy(ret + index + 1, n + index, strlen(n) - index);
    }
    
    return ret;
}