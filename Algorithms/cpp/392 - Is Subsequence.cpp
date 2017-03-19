class Solution {
public:
    bool isSubsequence(string s, string t) {
        // var
        int j = 0;
        
        for (int i = 0; i < s.length(); i++) {
            j = helper(t, j, s[i]) + 1;
            if (j <= 0)
                return false;
        }
        return true;
    }
    
    int helper(string s, int start, char target) {
        for (int i = start; i < s.length(); i++)
            if (s[i] == target)
                return i;
        return -1;
    }
};