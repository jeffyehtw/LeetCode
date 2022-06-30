class Solution {
public:
    bool isPalindrome(int x) {
        // var
        int num = x;
        int reverse = 0;
        
        if (x < 0)
            return false;
        
        while (num) {
            reverse *= 10;
            reverse += num % 10;
            num /= 10;
        }
        return x == reverse;
    }
};