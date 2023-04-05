class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int max = -1;
        int ret = 0;
        vector<int> primes;
        vector<bool> isprime;

        for (int i = 0; i < nums.size(); i++) {
            max = (nums[i] > max) ? nums[i] : max;
        }
        max++;

        isprime = vector<bool>(max, true);
        isprime[0] = false;
        isprime[1] = false;
        for (int i = 2; i <= max; i++) {
            for (int j = i * 2; j <= max; j += i) {
                isprime[j] = false;
            }
        }

        for (int i = 0; i < isprime.size(); i++) {
            if (isprime[i]) {
                primes.push_back(i);
            }
        }

        for (int i = 0; i < primes.size(); i++) {
            bool factor = false;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] % primes[i] == 0) {
                    if (factor == false) {
                        factor = true;
                        ret++;
                    }
                    while (nums[j] % primes[i] == 0) {
                        nums[j] /= primes[i];
                    }
                }
            }
        }

        return ret;
    }
};
