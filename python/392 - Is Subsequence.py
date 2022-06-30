class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        j = 0
        for i in s:
            if i in t[j:]:
                j += t[j:].index(i) + 1
            else:
                return False
        return True
        