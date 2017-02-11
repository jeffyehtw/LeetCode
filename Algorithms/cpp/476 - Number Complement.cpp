class Solution {
public:
    int findComplement(int num) {
        // var
        int result = 0;
        int power = 1;
        
        while (num) {
            result += (num % 2 == 0) ? power : 0;
            power <<= 1;
            num >>= 1;
        }
        return result;
    }
};