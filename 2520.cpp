class Solution {
public:
    int countDigits(int num) {
        int n = num;
        int ret = 0;
        
        while (n > 0) {
            if (n % 10 != 0 && num % (n % 10) == 0) {
                ret++;
            }
            n /= 10;
        }

        return ret;
    }
};
