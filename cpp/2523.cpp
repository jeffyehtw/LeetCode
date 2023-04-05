class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ret = { -1, -1 };
        vector<bool> isprimes;
        vector<int> primes;
        int min = INT_MAX;

        if (left > right) {
            return ret;
        }

        isprimes = vector<bool>(right + 1, true);
        isprimes[0] = false;
        isprimes[1] = false;
        for (int i = 2; i < isprimes.size(); i++) {
            if (!isprimes[i]) {
                continue;
            }
            if (i >= left && i <= right) {
                primes.push_back(i);
            }
            for (int j = i * 2; j < isprimes.size(); j += i) {
                isprimes[j] = false;
            }
        }

        for (int i = 1; i < primes.size(); i++) {
            if (primes[i] - primes[i - 1] < min) {
                ret[0] = primes[i - 1];
                ret[1] = primes[i];
                min = primes[i] - primes[i - 1];
            }
        }

        return ret;
    }
};
