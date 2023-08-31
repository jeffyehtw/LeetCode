class Solution {
public:
    int bitwiseComplement(int n) {
        int ret = 0;

        if (n == 0) {
            return 1;
        }
        for (int i = 0; (i < 32) && (n > 0); i++) {
            ret |= (((n & 1) == 1) ? 0 : 1) << i;
            n >>= 1;
        }

        return ret;
    }
};
