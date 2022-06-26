char * addBinary(char * a, char * b){
    char* p1 = NULL;
    char* p2 = NULL;
    int len1 = 0;
    int len2 = 0;
    int carry = 0;
    char* ret = NULL;

    if (strlen(a) > strlen(b)) {
        p1 = a;
        p2 = b;
        len1 = strlen(a);
        len2 = strlen(b);
    }
    else {
        p1 = b;
        p2 = a;
        len1 = strlen(b);
        len2 = strlen(a);
    }
    
    for (int i = 0; i < len1; i++) {
        int sum = carry;
        sum += p1[len1 - 1 - i] - '0';
        sum += i < len2 ? p2[len2 - 1 - i] - '0' : 0;
        carry = sum >> 1;
        sum %= 2;
        p1[len1 - 1 - i] = sum + '0';
    }
    
    if (carry == 0) {
        ret = malloc((len1 + 1) * sizeof(char));
        printf("123\n");
        memset(ret, 0, (len1 + 1) * sizeof(char));
        memcpy(ret, p1, len1);
    }
    else {
        len1++;
        ret = malloc((len1 + 1) * sizeof(char));
        memset(ret, 0, (len1 + 1) * sizeof(char));
        memcpy(ret + 1, p1, len1);
        ret[0] = carry + '0';
    }
    
    return ret;
}