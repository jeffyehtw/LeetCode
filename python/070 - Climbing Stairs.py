class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = list()
        dp.append(1)
        dp.append(2)
         
        if n < 1:
            return 0
         
        index = len(dp)
        while index < n:
            dp.append(dp[index - 1] + dp[index - 2])
            index += 1
        return dp[n - 1]