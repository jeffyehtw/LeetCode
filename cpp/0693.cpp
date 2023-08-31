class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int last = n & 1;

        n >>= 1;
        while (n > 0) {
            if (((n & 1) ^ last) == 0) {
                return false;
            }
            last = n & 1;
            n >>= 1;
        }

        return true;
    }
};
