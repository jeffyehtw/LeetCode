class Solution {
public:
    int findComplement(int num) {
        // var
        int exp = 1;
        int result = 0;
        
        while (num) {
            result += (num & 1) ? 0 : exp;
            exp <<= 1;
            num >>= 1;
        }
        return result;
    }
};