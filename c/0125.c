bool isalphanumeric(char c) {
    return isalpha(c) || isdigit(c);
}

bool isPalindrome(char * s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right) {
        while (isalphanumeric(s[left]) == false && left < right) {
            left++;
        }
        while (isalphanumeric(s[right]) == false && right > left) {
            right--;
        }
        
        if (tolower(s[left]) == tolower(s[right])) {
            left++;
            right--;
        }
        else {
            return false;
        }
    }
    return true;
}