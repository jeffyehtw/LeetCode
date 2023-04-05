class Solution {
public:
    int trailingZeroes(int n) {
        // var
        int tmp;
        int two = 0;
        int five = 0;
        
        // number of two
        tmp = n;
        for (int i = 1; tmp; i++, tmp >>= 1)
            two += tmp / 2;
        
        // number of five
        tmp = n;
        for (int i = 1; tmp; i++, tmp /= 5)
            five += tmp / 5;
         
        return min(two, five);
    }
};