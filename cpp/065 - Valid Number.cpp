class Solution {
public:
    bool isNumber(string s) {
        // var
        int i = 0;
        int n = s.length();
        bool is_numeric = false;

        // skip space
        for (; i < n && s[i] == ' '; i++);

        // skip sign
        i += (s[i] == '+' || s[i] == '-');

        while (i < n && isdigit(s[i])) {
            i++;
            is_numeric = true;
        }

        if (i < n && s[i] == '.') {
            i++;
            while (i < n) {
                if (!isdigit(s[i]))
                    break;
                i++;
                is_numeric = true;
            }
        }

        if (i < n && s[i] == 'e') {
            if (!is_numeric)
                return false;
            
            // init
            i++;
            is_numeric = false;
            
            // skip sign
            i += (s[i] == '+' || s[i] == '-') && (i < n);
            
            if (i == n)
                return false;

            while (i < n) {
                if (!isdigit(s[i]))
                    break;
                i++;
                is_numeric = true;
            }
        }

        while (i < n && s[i] == ' ')
            i++;
        
        return is_numeric && i == n;
    }
};