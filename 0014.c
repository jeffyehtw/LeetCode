char * longestCommonPrefix(char ** strs, int strsSize) {
    int len = 0;
    int min = INT_MAX;
    char* ret = NULL;
    
    for (int i = 0; i < strsSize; i++) {
        min = strlen(strs[i]) < min ? strlen(strs[i]) : min;
    }
    
    for (; len < min; len++) {
        int i = 1;
        for (; i < strsSize; i++) {
            if (strs[0][len] != strs[i][len]) {
                break;
            }
        }
        if (i < strsSize) {
            break;
        }
    }
    
    ret = malloc((len + 1) * sizeof(char));
    memset(ret, 0, (len + 1) * sizeof(char));
    memcpy(ret, strs[0], len);
    
    return ret;
}