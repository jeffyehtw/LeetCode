char* addStrings(char* num1, char* num2) {
    int n1 = strlen(num1);
    int n2 = strlen(num2);
    int max = n1 > n2 ? n1 : n2;
    int carry = 0;
    char* ret = NULL;
    char* sum = NULL;
    
    sum = malloc((max + 1) * sizeof(char));
    memset(sum, 0, (max + 1) * sizeof(char));
    
    for (int i = 0; i < max; i++) {
        sum[max - 1 - i] += (n1 - 1 - i > -1) ? num1[n1 - 1 - i] - '0' : 0;
        sum[max - 1 - i] += (n2 - 1 - i > -1) ? num2[n2 - 1 - i] - '0' : 0;
        sum[max - 1 - i] += carry;
        carry = sum[max - 1 - i] / 10;
        sum[max - 1 - i] %= 10;
        sum[max - 1 - i] += '0';
    }
    if (carry > 0) {
        ret = malloc((max + 1 + 1) * sizeof(char));
        memset(ret, 0, (max + 1 + 1) * sizeof(char));
        memcpy(ret + 1, sum, (max + 1) * sizeof(char));
        ret[0] = carry + '0';
        free(sum);
        return ret;
    }
    else {
        return sum;
    }
}