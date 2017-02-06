class Solution {
public:
    int romanToInt(string s) {
        // var
        int index;
        int result = 0;
        vector<string> THOUSAND {"", "M", "MM", "MMM"};
        vector<string> HUNDRED {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> TEN {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> ONE {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        // thousand
        int thousand = match_digit(&s, THOUSAND);
        result += thousand * 1000;
        
        // hundred
        int hundred = match_digit(&s, HUNDRED);
        result += hundred * 100;
        
        // ten
        int ten = match_digit(&s, TEN);
        result += ten * 10;
        
        // one
        int one = match_digit(&s, ONE);
        result += one;
        
        return result;
    }
    
    int match_digit(string *s, vector<string> strs) {
        // var
        string tmp;
        for (int i = strs.size() - 1; i > 0; i--) {
            tmp.assign(*s, 0, strs[i].length());
            if (tmp == strs[i]) {
                s->assign(*s, strs[i].length(), s->length() - strs[i].length());
                return i;
            }
        }
        return 0;
    }
};

