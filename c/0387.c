int firstUniqChar(char* s) {
    int index[26] = { 0 };
    int ret;
    
    for (int i = 0; i < strlen(s); i++) {
        index[s[i] - 'a']++;
    }
    for (int i = 0; i < strlen(s); i++) {
        if (index[s[i] - 'a'] == 1) {
            return i;
        }
    }
    
    return -1;
}