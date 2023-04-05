class Solution {
public:
    int reverse(int x) {
        bool positive = true;
        long ret = 0;

        if (x < 0) {
            if (x < -INT_MAX) {
                return 0;
            }
            positive = false;
            x = -x;
        }

        while (x > 0) {
            ret *= 10;
            ret += x % 10;
            x /= 10;

            if (positive && ret > INT_MAX) {
                return 0;
            } else if (!positive && -ret < INT_MIN) {
                return 0;
            }
        }

        ret = positive ? ret : -ret;

        if (ret > INT_MAX || ret < INT_MIN) {
            return 0;
        } else {
            return ret;
        }
    }
};
