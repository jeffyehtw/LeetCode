class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0;
        int flips = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                flips = min(ones, flips + 1);
            } else {
                ones++;
            }
        }

        return flips;
    }
};
