int strStr(char* haystack, char* needle) {
    if (strlen(haystack) < strlen(needle)) {
        return -1;
    }
    
    for (int i = 0; i < strlen(haystack); i++) {
        int match = 0;
        for (; match < strlen(needle); match++) {
            if (haystack[i + match] != needle[match]) {
                break;
            }
        }
        if (match == strlen(needle)) {
            return i;
        }
    }
    
    return -1;
}