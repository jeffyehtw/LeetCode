class Solution {
public:
    int arrangeCoins(int n) {
        for (int i = 1; i < INT_MAX; i++) {
            n -= i;
            if (n == 0) {
                return i;
            } else if (n < 0) {
                return i - 1;
            }
        }
        return -1;
    }
};
