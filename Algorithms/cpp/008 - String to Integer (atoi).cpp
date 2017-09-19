class Solution {
public:
    int myAtoi(string str) {
        // var
        int index = 0;
        long sign, result = 0;
        
        // skip invalid
        while (str[index] == ' ')
            index++;
        
        sign = str[index] == '-' ? -1 : 1;
        index += issign(str[index]);
            
        for (int i = index; i < str.length() && isdigit(str[i]); i++) {
            result *= 10;
            result += str[i] - '0';
            
            if (sign * result < INT_MIN)
                return INT_MIN;
            else if (sign * result > INT_MAX)
                return INT_MAX;
        }
        return sign * result;
    }
    
    bool issign(char c) {
        return c == '-' || c == '+';
    }
};