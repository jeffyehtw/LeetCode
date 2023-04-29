class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> last(primes.size(), 0);
        vector<long> dp;

        if (n == 1) {
            return 1;
        }

        dp.push_back(1);
        for (int i = 1; i < n; i++) {
            long min = primes[0] * dp[last[0]];

            for (int j = 1; j < primes.size(); j++) {
                if (min > primes[j] * dp[last[j]]) {
                    min = primes[j] * dp[last[j]];
                }
            }
            for (int j = 0; j < primes.size(); j++) {
                if (min == primes[j] * dp[last[j]]) {
                    last[j]++;
                }
            }

            dp.push_back(min);
        }

        return dp.back();
    }
};
