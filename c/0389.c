char findTheDifference(char* s, char* t) {
    int cnt[26] = { 0 };
    
    for (int i = 0; i < strlen(s); i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < strlen(t); i++) {
        if (cnt[t[i] - 'a'] < 1) {
            return t[i];
        }
        else {
            cnt[t[i] - 'a']--;
        }
    }
    return t[0];
}