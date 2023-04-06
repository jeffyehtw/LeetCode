class Solution {
public:
    string convertToBase7(int num) {
        string ret = "";
        int n = abs(num);

        if (num == 0) {
            return "0";
        }

        while (n > 0) {
            ret = to_string(n % 7) + ret;
            n /= 7;
        }

        return (num >= 0) ? ret : "-" + ret;
    }
};
