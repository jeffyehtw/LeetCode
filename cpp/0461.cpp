class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        int z = x ^ y;

        while (z > 0) {
            ret += (z & 1);
            z >>= 1;
        }

        return ret;
    }
};
