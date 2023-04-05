int tohappy(int n) {
    int h = 0;
    
    while (n) {
        h += (n % 10) * (n % 10);
        n /= 10;
    }
    
    return h;
}

bool isHappy(int n) {
    bool loop[8100];
    
    for (int i = 0; i < 8100; i++) {
        loop[i] = false;
    }
    
    n = tohappy(n);
    while (n != 1 && loop[n] == false) {
        loop[n] = true;
        n = tohappy(n);
    }
    
    return n == 1;
}