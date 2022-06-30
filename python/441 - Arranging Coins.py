class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        # m (1 + m) / 2 >= n
        return int((-1 + math.pow(1 + 8 * n, 0.5)) / 2)