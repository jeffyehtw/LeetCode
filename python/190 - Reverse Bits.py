class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        exp = 2**31
        while n > 0:
            ans += (n % 2) * exp
            exp /= 2
            n /= 2
        return ans