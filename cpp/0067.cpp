class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string ret = "";
        
        while (i > -1 || j > -1) {
            int sum = 0;
            if (i > -1) {
                sum += a[i] - '0';
            }
            if (j > -1) {
                sum += b[j] - '0';
            }
            sum += carry;
            carry = sum / 2;
            sum %= 2;
            
            i--;
            j--;

            ret = ((sum == 0) ? "0" : "1") + ret;
        }
        if (carry > 0) {
            ret = "1" + ret;
        }

        return ret;
    }
};
