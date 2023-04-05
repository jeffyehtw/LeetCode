class Solution {
public:
    int getLucky(string s, int k) {
        int ret = 0;
        string num = "";

        for (int i = 0; i < s.length(); i++) {
            num += to_string(int(s[i] - 'a' + 1));
        }
        
        for (int i = 0; i < num.length(); i++) {
            ret += (num[i] - '0');
        }
        while (k > 1) {
            int sum = 0;
            
            while (ret > 0) {
                sum += ret % 10;
                ret /= 10;
            }
            ret = sum;
            k--;
        }

        return ret;
    }
};
