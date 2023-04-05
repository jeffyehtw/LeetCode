bool isIsomorphic(char* s, char* t) {
    int s2t[256];
    int t2s[256];
    
    if (strlen(s) != strlen(t)) {
        return false;
    }
    
    for (int i = 0; i < 256; i++) {
        s2t[i] = -1;
        t2s[i] = -1;
    }
    
    for (int i = 0; i < strlen(s); i++) {
        if ((s2t[s[i]] == -1) && (t2s[t[i]] == -1)) {
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        else if (s2t[s[i]] != t[i]) {
            return false;
        }
    }
    
    return true;
}