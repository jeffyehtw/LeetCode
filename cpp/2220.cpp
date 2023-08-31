class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ret = 0;
        
        start ^= goal;
        while (start > 0) {
            ret += start & 1;
            start >>= 1;
        }

        return ret;
    }
};
