class Solution {
public:
    int myAtoi(string str) {
        // remove space
        while (str[0] == ' ')
            str.assign(str, 1, str.length() - 1);
        
        if (str == "")
            return 0;
        
        // var
        long long result = 0;
        int sign = str[0] == '-' ? -1 : 1;
        
        // remove sign
        if (str[0] == '+' || str[0] == '-')
            str.assign(str, 1, str.length() - 1);
            
        if (!isdigit(str[0]))
            return 0;

        for (int i = 0; i < str.length(); i++) {
            if (!isdigit(str[i]))
                break;
            result *= 10;
            result += str[i] - '0';
            
            if (result * sign > INT_MAX)
                return INT_MAX;
            if (result * sign < INT_MIN)
                return INT_MIN;
        }
        
        result *= sign;
        
        if (result > INT_MAX)
            return INT_MAX;
        if (result < INT_MIN)
            return INT_MIN;
        
        return result;
    }
};