class Solution {
public:
    int findNthDigit(int n) {
        int bit = 1;
        long count = 0;
        long prev_count = 0;
        
        for (;; bit++) {
            prev_count = count;
            count += pow(10, bit - 1) * 9 * bit;
            if (count > n)
                break;
        }
        
        int base = pow(10, bit - 1) - 1;
        int offset = (n - prev_count) % bit;
        int target = base + (n - prev_count) / bit;
        
        if (offset % bit == 0)
            return target % 10;
        else {
            target++;
            target /= pow(10, bit - offset);
            target %= 10;
            return target;
        }
    }
};