class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # int to string
        s = str(x)
        
        # bound
        max = math.pow(2, 31)
        
        if x < 0:
            # remove '-'
            s = s[1:]
            
            # reverse
            s = s[::-1]
            
            ans = -1 * int(s)
            
            if ans >= -1 * max + 1:
                return ans
        else:
            s = s[::-1]
            ans = int(s)
            
            if ans <= max - 1:
                return ans
        return 0
        