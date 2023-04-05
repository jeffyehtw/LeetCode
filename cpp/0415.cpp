class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        int carry = 0;
        string ret(max(m, n) + 1, '0');

        num1 = string(ret.length() - m, '0') + num1;
        num2 = string(ret.length() - n, '0') + num2;

        for (int i = ret.length() - 1; i > 0; i--) {
            int sum = 0;
            
            sum += (num1[i] - '0');
            sum += (num2[i] - '0');
            sum += carry;

            carry = sum / 10;
            sum %= 10;
            ret[i] += sum;
        }
        if (carry > 0) {
            ret[0] += carry;
        }

        return (ret[0] == '0') ? string(ret.begin() + 1, ret.end()) : ret;
    }
};
