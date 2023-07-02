class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> primes(n + 1, true);
        vector<vector<int>> ret;

        primes[0] = false;
        primes[1] = false;
        for (int i = 2; i < n + 1; i++) {
            if (!primes[i]) {
                continue;
            }
            for (int j = i * 2; j < n + 1; j += i) {
                primes[j] = false;
            }
        }

        for (int i = 2; (i < n + 1) && (i <= n - i); i++) {
            if (primes[i] && primes[n - i]) {
                ret.push_back({ i, n - i });
            }
        }

        return ret;
    }
};
