class Solution {
public:
    int hammingDistance(int x, int y) {
        // var
        int result = 0;
        
        while (x || y) {
            result += (x % 2 xor y % 2);
            x >>= 1;
            y >>= 1;
        }
        return result;
    }
};