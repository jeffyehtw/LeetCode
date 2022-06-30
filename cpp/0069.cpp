class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0)
            return 0;
        else if (x == 1)
            return 1;
        
        long prev = 0;
        long left = 0;
        long right = x / 2 + 1;
        
        while (1) {
            long mid = (left + right) / 2;
            long result = mid * mid;
            
            if (result == x) 
                return mid;
            else if (result < x)
                left = mid;
            else
                right = mid;
                
            if (mid == prev)
                break;
                
            prev = mid;
        }
        return prev;
    }
};