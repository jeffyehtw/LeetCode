class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        # variables
        two = 0
        five = 0

        temp = n
        while temp > 0:
            temp /= 2
            two += temp
            
        temp = n
        while temp > 0:
            temp /= 5
            five += temp
            
        return min(two, five)