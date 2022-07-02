bool isleft(char c) {
    return (c == '[' || c == '{' || c == '(');
}

bool isValid(char * s) {
    int len = strlen(s);
    char queue[10001];
    int size = 0;
    
    memset(&queue, 0, sizeof(queue));
    
    if (len & 1) {
        return false;
    }
    
    for (int i = 0; i < len; i++) {
        if (isleft(s[i])) {
            queue[size] = s[i];
            size++;
        }
        else {
            char c;
            if (size < 1) {
                return false;
            }
            switch (s[i]) {
                case ']':
                    c = '[';
                    break;
                case ')':
                    c = '(';
                    break;
                case '}':
                    c = '{';
                    break;        
            }
            if (c == queue[size - 1]) {
                queue[size - 1] = '\0';
                size--;
            }
            else {
                return false;
            }
        }
    }
    
    return size == 0;
}