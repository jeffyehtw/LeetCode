class Solution {
public:
    int hammingWeight(uint32_t n) {
        // var
        int result = 0;
        
        while (n) {
            result += n % 2;
            n >>= 1;
        }
        
        return result;
    }
};