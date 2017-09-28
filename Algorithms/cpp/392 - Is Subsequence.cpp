class Solution {
public:
    bool isSubsequence(string s, string t) {
        // var
        int index = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // var
            size_t next = t.find(s[i], index);
            
            if (next == string::npos)
                return false;
            
            index = next + 1;
        }
        return true;
    }
};