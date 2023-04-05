class Solution {
public:
    int myAtoi(string s) {
        bool positive = true;
        long index = 0;
        long ret = 0;

        while (s[index] == ' ') {
            index++;
        }

        if (s[index] == '-') {
            positive = false;
            index++;
        } else if (s[index] == '+') {
            positive = true;
            index++;
        }

        if (!isdigit(s[index])) {
            return 0;
        }
        
        for (; index < s.length(); index++) {
            if (isdigit(s[index])) {
                ret *= 10;
                ret += (s[index] - '0');
            } else {
                break;
            }

            if (positive && ret > INT_MAX) {
                return INT_MAX;
            } else if (!positive && -ret < INT_MIN) {
                return INT_MIN;
            }
        }

        return positive ? ret : -ret;
    }
};
