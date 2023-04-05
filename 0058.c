int lengthOfLastWord(char * s) {
    int count = 0;
    int index = strlen(s) - 1;
    
    for (; index > -1 && s[index] == ' '; index--);
    for (; index > -1 && s[index] != ' '; index--, count++);
    
    return count;
}