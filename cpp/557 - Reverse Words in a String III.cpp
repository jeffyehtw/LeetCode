class Solution {
public:
    string reverseWords(string s) {
        // var
        size_t start = 0;
        
        while (start <= s.length()) {
            // var
            size_t next = s.find(" ", start);
        
            reverse(s.begin() + start, s.begin() + min(next, s.length()));
            
            if (next == string::npos)
                break;
           
            start = next + 1;
        }
        return s;
    }
};