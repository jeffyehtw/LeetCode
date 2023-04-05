class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        int m = abs(n);

        if (m == 0) {
            return 1;
        } else if (m == 1) {
            return n > 0 ? x : 1 / x;
        } else {
            double m12 = myPow(x, m / 2);
            ret = m12 * m12;
            if (m % 2 == 1) {
                ret *= x;
            }
            return n > 0 ? ret : 1 / ret;
        }
    }
};
