class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        
        i = len(digits) - 1
        digits[i] += 1
        
        while i > 0:
            digits[i - 1] += digits[i] / 10
            digits[i] %= 10
            i -= 1
            
        while digits[0] > 9:
            digits.insert(0, digits[0] / 10)
            digits[1] %= 10
            
        return digits