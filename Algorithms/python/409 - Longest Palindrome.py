class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = [str(i) for i in s]
        set_s = list(set(s))
        
        count = 0
        for i in set_s:
            count += s.count(i) / 2 * 2
        
        # center
        if count < len(s):
            count += 1
            
        return count