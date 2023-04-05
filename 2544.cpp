class Solution {
public:
    int alternateDigitSum(int n) {
        int ret = 0;
        int len = 0;
        
        for (len = 0; n > 0; len++) {
            ret += ((len % 2) ? 1 : -1) * (n % 10);
            n /= 10;
        }

        return (len % 2 == 0) ? ret : -ret;
    }
};
