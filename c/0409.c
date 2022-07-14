int longestPalindrome(char* s) {
    int upper[26] = { 0 };
    int lower[26] = { 0 };
    int ret = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        if (isupper(s[i])) {
            upper[s[i] - 'A']++;
        }
        else {
            lower[s[i] - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        ret += upper[i] >> 1;
        ret += lower[i] >> 1;
    }
    ret <<= 1;
    ret += ret < strlen(s) ? 1 : 0;
    
    return ret;
}