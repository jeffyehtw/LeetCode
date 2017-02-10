class Solution {
public:
    int reverse(int x) {
        if (abs(x) < 10)
            return x;
            
        // var
        long long result = 0;
        vector<int> bits;
        bool is_positive = x >= 0;
        
        if (!is_positive)
            x *= -1;
        
        // split
        while (x) {
            bits.push_back(x % 10);
            x /= 10;
        }
        
        for (int i = 0; i < bits.size(); i++) {
            result *= 10;
            result += bits[i];
        }
        
        result = is_positive ? result : -1 * result;
        
        return (result < INT_MIN || result >INT_MAX) ? 0 : result;
    }
};