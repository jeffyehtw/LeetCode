bool canConstruct(char* ransomNote, char* magazine) {
    int cnt[26] = { 0 };
    
    for (int i = 0; i < strlen(magazine); i++) {
        cnt[magazine[i] - 'a']++;
    }
    for (int i = 0; i < strlen(ransomNote); i++) {
        if (cnt[ransomNote[i] - 'a'] > 0) {
            cnt[ransomNote[i] - 'a']--;
        }
        else {
            return false;
        }
    }
    return true;
}