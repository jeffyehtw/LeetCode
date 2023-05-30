class Solution {
public:
    bool checkOnesSegment(string s) {
        int cont = 0;
        int ones = 0;
        int most = 0;

        if (s.length() == 0) {
            return false;
        } else if (s.length() == 1) {
            return s[0] == '1';
        }

        ones = (s[0] == '1');
        cont = ones;
        most = ones;
        for (int i = 1; i < s.length(); i++) {
            ones += (s[i] == '1');
            if (s[i] == '0') {
                cont = 0;
            } else {
                cont++;
                most = max(most, cont);
            }
        }
        return ones == most;
    }
};
