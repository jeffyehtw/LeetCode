class Solution {
public:
    int trailingZeroes(int n) {
        int num2 = 0;
        int num5 = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = i; (j > 1) && (j % 2 == 0); j /= 2) {
                num2++;
            }
            for (int j = i; (j > 1) && (j % 5 == 0); j /= 5) {
                num5++;
            }
        }

        return min(num2, num5);
    }
};
