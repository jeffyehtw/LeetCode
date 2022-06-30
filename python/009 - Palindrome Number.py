class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        y = str(x)[::-1]
        index = 0
        while index < len(x):
            if x[index] != y[index]:
                return False
            index += 1
        return True