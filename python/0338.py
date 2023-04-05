class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        ans = []
        for i in range(0, num + 1):
            # decimal to binary
            bits = list(bin(i)[2:])
            
            count = 0
            for x in bits:
                if x == '1':
                    count += 1
            ans.append(count)
        return ans