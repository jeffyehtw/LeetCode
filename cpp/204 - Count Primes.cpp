class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
            
        // var
        int count = 1;
        vector<bool> prime(n, true);
        int m = prime.size();
        
        // init
        for (long i = 3; i < n; i += 2) {
            if (prime[i]) {
                for (long j = i * i; j < n; j += i)
                    prime[j] = false;
                count++;
            }
        }
        return count;
    }
};