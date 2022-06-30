class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return 0
        
        prime = [True] * n
        prime[0] = False
        prime[1] = False
        
        i = 2
        count = 0
        while i < n:
            if prime[i]:
                count += 1
                j = 2 * i
                while j < n:
                    prime[j] = False
                    j += i
            i += 1

        return count