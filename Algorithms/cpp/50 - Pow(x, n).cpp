class Solution {
public:
    double myPow(double x, int n) {
        // var
        double result = 1;
        unsigned long long p;
        
        p = n < 0 ? -n : n; 
        x = n < 0 ? 1 / x : x;
        
        while (p) {
            if (p & 1) {
                result *= x;
            }
            x *= x;
            p >>= 1;
        }
        return result;
    }
};