class Solution {
public:
    bool isHappy(int n) {
        // var
        map<int, bool> m;
        
        while (1) {
            // var
            int sum = 0;
            
            while (n) {
                // var
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            
            n = sum;
            
            if (m.find(n) == m.end())
                m[sum] = true;
            else if (n == 1)
                return true;
            else
                return false;
        }
    }
};