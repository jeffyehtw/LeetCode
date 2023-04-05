class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int index = digits.size() - 1;

        digits[index]++;
        carry = digits[index] / 10;
        digits[index] %= 10;
        index--;

        while (index > -1 && carry > 0) {
            digits[index] += carry;
            carry = digits[index] / 10;
            digits[index] %= 10;
            index--;
        }
        
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
