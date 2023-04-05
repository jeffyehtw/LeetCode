class Solution {
public:
    int integerReplacement(long n) {
        if (n == 1)
            return 0;
            
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        } 
        else {
            int a = integerReplacement(n + 1);
            int b = integerReplacement(n - 1);
            return 1 + min(a, b);
        }
    }
};