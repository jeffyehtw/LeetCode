class Solution {
private:
    int count(int val) {
        int ret = 0;

        while (val > 0) {
            ret += val & 1;
            val >>= 1;
        }

        return ret;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ret = 0;
        unsigned int prime = 0xa08a28ac;

        for (int i = left; i <= right; i++) {
            if ((prime & (1 << count(i))) > 0) {
                ret++;
            }
        }

        return ret;
    }
};
