class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // var
        uint32_t result = 0;
        uint32_t exp = INT_MAX + 1;
        
        while (n) {
            result += n % 2 ? exp : 0;
            exp >>= 1;
            n >>= 1;
        }
        return result;
    }
};