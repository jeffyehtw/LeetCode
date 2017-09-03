class Solution {
public:
    int minSteps(int n) {
        // var
        int t[6] = { 
            0, 0, 2, 3, 4, 5 
        };
        
        if (n < 6) {
            return t[n < 0 ? 0 : n];
        }
    
        for (int i = 2; i < pow(n, 0.5) + 1; i++) {
            if (n % i == 0) {
                // var
                int a = min(i, n / i);
                int b = max(i, n / i);
                
                return minSteps(b) + 1 + (a - 1);
            }
        }
        return n;
    }
};