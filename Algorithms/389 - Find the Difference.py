class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        
        s = sorted(s)
        t = sorted(t)
        
        i = 0
        while i < len(s):
            if t[i] != s[i]:
                return t[i]
            i += 1
        return t[len(t) - 1]