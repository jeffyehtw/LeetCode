class Solution {
public:
    bool isHappy(int n) {
        vector<bool> seen(1000, false);

        while (n != 1) {
            int sum = 0;
        
            while (n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if (seen[n]) {
                return false;
            }
            seen[n] = true;
            
        }

        return true;
    }
};
