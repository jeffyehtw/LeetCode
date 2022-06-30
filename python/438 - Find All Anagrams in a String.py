class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        if len(s) < len(p):
            return []
        
        # variables
        buf = [0] * 26
        count = [0] * 26
        ans = []
        
        # init
        for i in range(0, len(p)):
            buf[ord(s[i]) - ord('a')] += 1
            count[ord(p[i]) - ord('a')] += 1
            
        # index 0
        if self.is_equal(buf, count):
            ans.append(0)
            
        # compare
        for i in range(0, len(s) - len(p)):
            # update
            buf[ord(s[i]) - ord('a')] -= 1
            buf[ord(s[i + len(p)]) - ord('a')] += 1
            
            if self.is_equal(buf, count):
                ans.append(i + 1)
        
        return ans
            
    def is_equal(self, buf, count):
        for i in range(0, 26):
            if buf[i] != count[i]:
                return False
        return True
            
        