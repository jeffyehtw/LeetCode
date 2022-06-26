int countPrimeSetBits(int left, int right){
    int ret = 0;
    bool primes[20];
    
    memset(primes, true, sizeof(primes));
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < (20 >> 1); i++) {
        for (int j = i * 2; j < 20; j += i) {
            primes[j] = false;
        }
    }

    for (int i = left; i <= right; i++) {
        int n = i;
        int bits = 0;
        
        while (n > 0) {
            bits += n & 1;
            n >>= 1;
        }
        if (primes[bits] == true) {
            ret++;
        }
    }
    
    return ret;
}