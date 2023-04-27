class Solution {
public:
    int trailingZeroes(int n) {
        int num5 = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = i; (j > 1) && (j % 5 == 0); j /= 5) {
                num5++;
            }
        }

        return num5;
    }
};
