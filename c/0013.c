int toindex(char c) {
    return c - 'A';
}

int romanToInt(char* s) {
    int ret = 0;
    int n = strlen(s);
    int dec[26] = { 0 };
    
    dec[toindex('I')] = 1;
    dec[toindex('V')] = 5;
    dec[toindex('X')] = 10;
    dec[toindex('L')] = 50;
    dec[toindex('C')] = 100;
    dec[toindex('D')] = 500;
    dec[toindex('M')] = 1000;
    
    for (int i = 0; i < n;) {
        int len = 1;
        int acc = dec[toindex(s[i])];
        
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                acc += dec[toindex(s[j])];
                len++;
            }
            else if (dec[toindex(s[i])] < dec[toindex(s[j])]) {
                acc = -1 * acc + dec[toindex(s[j])];
                len++;
                break;
            }
            else {
                break;
            }
        }
        
        i += len > 0 ? len : 1;
        ret += acc;
    }
    
    return ret;
}