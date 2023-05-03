class Solution {
public:
    bool reorderedPowerOf2(int n) {
        bool ret = false;
        vector<int> digit(10, 0);
        int max = 0;
        int power = 1;

        while (n > 0) {
            digit[n % 10]++;
            n /= 10;
        }
        for (int i = digit.size() - 1; i > -1; i--) {
            for (int j = 0; j < digit[i]; j++) {
                max *= 10;
                max += i;
            }
        }
        
        while ((power <= max) && !ret) {
            int p = power;
            vector<int> d = digit;
            int idx = 0;

            while (p > 0) {
                d[p % 10]--;
                if (d[p % 10] < 0) {
                    break;
                }
                p /= 10;
            }
            for (; idx < 10; idx++) {
                if (d[idx] != 0) {
                    break;
                }
            }
            if (idx == 10) {
                ret = true;
            }
            power <<= 1;
        }
        
        return ret;
    }
};
