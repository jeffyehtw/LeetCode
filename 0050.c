#define MAX 32
double myPow(double x, int n){
    double values[MAX];
    unsigned long absn = n > 0 ? n : -1 * (unsigned long)n;
    unsigned long power = 1;
    int index = 0;
    double ret = 1;
    
    while (absn > 1) {
        absn >>= 1;
        power <<= 1;
        index++;
    }
    
    memset(values, 0, sizeof(values));
    values[0] = x;
    for (int i = 1; i <= index; i++) {
        values[i] = values[i - 1] * values[i - 1];
    }
    
    absn = n > 0 ? n : -1 * (unsigned long)n;
    for (int i = index; i >= 0; i--, power >>= 1) {
        while (absn >= power) {
            absn -= power;
            ret *= values[i];
        }
    }

    return n > 0 ? ret : 1 / ret;
}