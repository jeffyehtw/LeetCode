class Solution {
private:
    int len(int val) {
        int ret = 0;
        
        while (val) {
            ret++;
            val >>= 1;
        }

        return ret;
    }
public:
    int rangeBitwiseAnd(int left, int right) {
        int length;

        if (left == right) {
            return left;
        } else if (left + 1 == right) {
            return left & right;
        }

        length = len(right - left);
        left >>= length;
        left <<= length;
        left &= right;
        
        return left;
    }
};
