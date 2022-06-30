class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = [0] * 26
        for c in s:
            count[ord(c) - 97] += 1
        
        for c in s:
            if count[ord(c) - 97] == 1:
                return s.index(c)
        return -1