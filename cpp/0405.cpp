class Solution {
public:
    string toHex(int num) {
        string ret;
        char d2h[16] = {
            '0', '1', '2', '3',
            '4', '5', '6', '7',
            '8', '9', 'a', 'b',
            'c', 'd', 'e', 'f'
        };
        unordered_map<char, int> h2d;
        bool negative = (num >= 0) ? false : true;

        if (num == 0) {
            return "0";
        }

        for (int i = 0; i < 16; i++) {
            h2d[d2h[i]] = i;
        }
        num = abs(num);
        while (num > 0) {
            ret = string(1, d2h[num % 16]) + ret;
            num >>= 4;
        }
        if (negative) {
            int carry = 1;
            for (int i = 0; i < ret.length(); i++) {
                ret[i] = d2h[abs(h2d[ret[i]] - 15)];
            }
            for (int i = ret.length() - 1; (i > -1) && (carry > 0); i--) {
                int sum = h2d[ret[i]] + carry;
                carry = sum / 16;
                sum %= 16;
                ret[i] = d2h[sum];
            }
            ret = string(8 - ret.length(), 'f') + ret;
        }

        return ret;
    }
};
