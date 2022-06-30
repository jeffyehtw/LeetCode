class Solution {
public:
    int strStr(string haystack, string needle) {
        // var
        int h_len = haystack.length();
        int n_len = needle.length();
        
        if (h_len == n_len)
            return haystack == needle ? 0 : -1;
        else if (h_len < n_len)
            return -1;
        else
            return haystack.find(needle);
    }
};