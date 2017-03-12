class Solution {
public:
    int countSegments(string s) {
        if (s == "")
            return 0;
            
        // var
        int result = 0;
        int n = s.length();
        
        // init 
        s += ' ';
        
        // run
        for (int i = 0; i < n; i++) 
            if (s[i] != ' ' && s[i + 1] == ' ')
                result++;
                
        return result;
    }
};