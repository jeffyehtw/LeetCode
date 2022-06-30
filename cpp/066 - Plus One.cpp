class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // init
        digits[digits.size() - 1]++;
        
        for (int i = digits.size() - 1; i > -1; i--) {
            if (digits[i] >= 10 && i > 0) {
                digits[i - 1]++;
                digits[i] %= 10;
            }
        }
        
        if (digits[0] >= 10) {
            digits.insert(digits.begin(), 1, 1);
            digits[1] %= 10;
        }
        
        return digits;
    }
};