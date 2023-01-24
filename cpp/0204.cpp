class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> primes(n, true);

        if (n <= 2) {
            return 0;
        }

        for (int i = 2; i < n; i++) {
            if (!primes[i]) {
                continue;
            }
            for (int j = i << 1; j < n; j += i) {
                primes[j] = false;
            }
        }

        for (int i = 2; i < n; i++) {
            if (primes[i]) {
                count++;
            }
        }

        return count;
    }
};