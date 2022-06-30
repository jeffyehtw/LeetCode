class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // var
        int mask = INT_MAX;
        
        while ((m & mask) != (n & mask))
            mask <<= 1;
            
        return m & mask;
    }
};