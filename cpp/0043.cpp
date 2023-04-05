class Solution {
private:
    string add(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        string ret(max(m, n), '0');
        int carry = 0;

        num1 = string(ret.length() - m, '0') + num1;
        num2 = string(ret.length() - n, '0') + num2;

        for (int i = ret.length() - 1; i > -1; i--) {
            int sum = carry;

            sum += (num1[i] - '0');
            sum += (num2[i] - '0');

            carry = sum / 10;
            sum %= 10;

            ret[i] = (sum + '0');
        }
        if (carry > 0) {
            ret = string(1, (carry + '0')) + ret;
        }
        
        return ret;
    }
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        string ret(m + n, '0');
        int index = 0;

        for (int i = 0; i < num2.length(); i++) {
            int carry = 0;
            string tmp = num1;

            for (int j = tmp.length() - 1; j > -1; j--) {
                int sum = 0;
                
                sum += (tmp[j] - '0');
                sum *= (num2[num2.length() - 1 - i] - '0');
                sum += carry;

                carry = sum / 10;
                sum %= 10;

                tmp[j] = (sum + '0');
            }
            if (carry > 0) {
                tmp = string(1, (carry + '0')) + tmp;
            }
            tmp += string(i, '0');

            ret = add(tmp, ret);
        }

        for (; index < ret.length() && ret[index] == '0'; index++);
        ret = string(ret.begin() + index, ret.end());

        return ret == "" ? "0" : ret;
    }
};
