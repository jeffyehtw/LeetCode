class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ret(2, 0);

        for (int i = 0; (i < 32) && (n > 0); i++) {
            ret[i & 1] += n & 1;
            n >>= 1;
        }

        return ret;
    }
};
