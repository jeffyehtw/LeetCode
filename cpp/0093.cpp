class Solution {
private:
    vector<string> ret;
    bool valid(string s) {
        int i = 0;
        int sum = 0;

        if (s == "0") {
            return true;
        }

        for (; i < s.length() && s[i] == '0'; i++);
        if (i > 0) {
            return false;
        }

        for (i = 0; i < s.length(); i++) {
            sum *= 10;
            sum += (s[i] - '0');
        }

        return ((sum >= 0) && (sum <= 255));
    }
    void backtrack(string s, int idx, string ss, int cnt) {
        if ((cnt > 4) || (idx > s.length())) {
            return;
        } else if (cnt == 4) {
            if (idx == s.length()) {
                ret.push_back(string(ss, 0, ss.length() - 1));
            }
            return;
        }

        for (int i = 1; (i <= 3) && (idx + i <= s.length()); i++) {
            string sub(s, idx, i);

            if (valid(sub)) {
                backtrack(s, idx + i, ss + sub + ".", cnt + 1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, "", 0);
        return ret;
    }
};
