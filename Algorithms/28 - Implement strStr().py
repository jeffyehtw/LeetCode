class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        h_len = len(haystack)
        n_len = len(needle)
        
        # specific
        if h_len < n_len:
            return -1
        elif h_len == n_len:
            if haystack == needle:
                return 0
            else:
                return -1
        
        # compare
        for i in range(0, h_len - n_len + 1):
            if haystack[i:i + n_len] == needle:
                return i
        return -1