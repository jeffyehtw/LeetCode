class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // var
        int _min = 1;
        vector<int> dp({ 1 });
        vector<int> index(primes.size(), 0);
        
        while (dp.size() < n) {
            // var
            int _min = dp[index[0]] * primes[0];
            
            for (int i = 1; i < primes.size(); i++)
                _min = min(_min, dp[index[i]] * primes[i]);
            
            dp.push_back(_min);
            
            for (int i = 0; i < primes.size(); i++)
                index[i] += dp.back() == dp[index[i]] * primes[i];
        }
        return dp[n - 1];
    }
};