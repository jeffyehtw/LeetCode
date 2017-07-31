class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.length() / 2; i++) {
            if (s.length() % i != 0)
                continue;
            
            // var
            bool ok = true;
            string tmp = s.substr(0, i);
        
            for (int j = i; j < s.length() && ok; j += i) {
                if (tmp != s.substr(j, i))
                    ok = false;
            }
            
            if (ok)
                return true;
        }
        return false;
    }
};