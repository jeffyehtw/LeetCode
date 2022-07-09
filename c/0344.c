void swap(char* p1, char* p2) {
    char c = *p1;
    *p1 = *p2;
    *p2 = c;
}

void reverseString(char* s, int sSize) {
    for (int i = 0; i < (sSize >> 1); i++) {
        swap(&s[i], &s[sSize - 1 - i]);
    }
}