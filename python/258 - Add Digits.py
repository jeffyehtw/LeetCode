class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num > 9:
            temp = num % 9
            if temp == 0:
                return 9
            return temp
        else:
            return num