class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.length(); ) {
            // var
            int space = s.find(" ", i);
            
            if (space == string::npos)
                space = s.length();
            
            // swap
            for (int j = 0; j < (space - i) / 2; j++) {
                swap(s[i + j], s[space - 1 - j]);
            }
            
            i = space + 1;
        }
        
        return s;
    }
};