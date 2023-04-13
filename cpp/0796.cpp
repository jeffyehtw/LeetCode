class Solution {
public:
    bool rotateString(string s, string goal) {
        int idx = 0;
        int m = s.length();
        int n = goal.length();

        if (m != n) {
            return false;
        } else if (s == goal) {
            return true;
        }

        for (int i = 1; i < m; i++) {
            string r;
            if (s[0] != goal[i]) {
                continue;
            }
            
            r += string(goal.begin() + i, goal.end());
            r += string(goal.begin(), goal.begin() + i);

            if (s == r) {
                return true;
            }
        }

        return false;
    }
};
