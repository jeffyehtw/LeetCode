class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        regex = re.compile('[^a-zA-Z0-9]+')
        s = regex.sub('', s)
        s = s.lower()
        
        i = 0
        while i < len(s) / 2:
            if s[i] != s[len(s) - 1 - i]:
                return False
            i += 1
        return True