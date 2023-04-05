class Solution {
public:
    int tribonacci(int n) {
        vector<int> fibs(n + 1, 1);

        fibs[0] = 0;
        for (int i = 3; i <= n; i++) {
            fibs[i] = fibs[i - 3] + fibs[i - 2] + fibs[i - 1];
        }

        return fibs[n];
    }
};
