class Solution {
public:
    bool checkRecord(string s) {
        int absences = 0;
        int late = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                absences++;
                late = 0;
                if (absences >= 2) {
                    return false;
                }
            } else if (s[i] == 'L') {
                late++;
                if (late >= 3) {
                    return false;
                }
            } else {
                late = 0;
            }
        }

        return true;
    }
};
