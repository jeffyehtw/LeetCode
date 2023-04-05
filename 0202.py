class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # showed num
        arr = [n]
        
        while 1:
            digits = [int(i) for i in str(n)]
            n = 0
            for i in digits:
                n += i * i
            if n in arr:
                break
            arr.append(n)
        return (n == 1)