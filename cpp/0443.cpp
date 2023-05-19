class Solution {
private:
    int help(vector<char>& chars, int idx, int num) {
        vector<char> digits;

        if (num == 1) {
            return 0;
        }

        while (num > 0) {
            digits.push_back(('0' + num % 10));
            num /= 10;
        }
        for (int i = 0; i < digits.size(); i++) {
            chars[idx + i] = digits[digits.size() - 1 - i];
        }

        return digits.size();
    }
public:
    int compress(vector<char>& chars) {
        int cnt = 0;
        int ret = 0;
        char c;

        if (chars.size() <= 1) {
            return chars.size();
        }

        c = chars[0];
        cnt = 1;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == c) {
                cnt++;
            } else {
                chars[ret] = c;
                ret++;
                ret += help(chars, ret, cnt);
                c = chars[i];
                cnt = 1;
            }
        }
        if (cnt > 0) {
            chars[ret] = c;
            ret++;
            ret += help(chars, ret, cnt);
        }

        return ret;
    }
};
