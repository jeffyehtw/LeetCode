class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        # variables
        table = [1, 10, 91]
        
        for i in range(3, n + 1):
            # temp counter
            count = 9
            
            # init
            table.append(9)

            for j in range(1, i):
                table[i] *= count
                count -= 1
                
            table[i] += table[i - 1]
            
        return table[n]