class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        s = s[::-1]
        
        i = 0
        while i < len(s): 
            digit = ord(s[i]) - ord('A') + 1
            base = math.pow(26, i)
            ans += digit * base
            i += 1
        return int(ans)
