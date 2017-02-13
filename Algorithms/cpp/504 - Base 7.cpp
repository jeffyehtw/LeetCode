class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        
        // var
        string result;
        bool is_negative = num < 0;
        
        // run
        num = is_negative ? -1 * num : num;
        while (num) {
            result = char(num % 7 + '0') + result;
            num /= 7;
        }
        return is_negative ? '-' + result : result;
    }
};