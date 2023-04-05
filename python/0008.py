class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        # remove space
        i = 0
        while i < len(str):
            if str[i] != ' ':
                break
            i += 1
        str = str[i:]
        
        if len(str) == 0:
            return 0
        
        sign = 1
        if str[0] == '-' or str[0] == '+':
            if str[0] == '-':
                sign = -1
            str = str[1:]
        
        i = 0
        num = 0
        for c in str:
            # error case
            if not c.isdigit():
                if c == '+' or c == '-':
                    return 0
                else:
                    break
            else:
                num *= 10
                num += ord(c) - ord('0')
        
        val = num * sign
        
        # overflow
        if val > 2147483647:
            return 2147483647
        elif val < -2147483648:
            return -2147483648
        else:
            return val
        