class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1 = [int(i) for i in num1]
        num2 = [int(i) for i in num2]
        
        max_len = max(len(num1), len(num2)) + 1
        
        for i in range(0, max_len - len(num1)):
            num1.insert(0, 0)
        for i in range(0, max_len - len(num2)):
            num2.insert(0, 0)
        
        ans = [0] * max_len
        
        for i in range(0, max_len):
            ans[i] = num1[i] + num2[i]
            
        ans.reverse()
        
        for i in range(0, max_len - 1):
            ans[i + 1] += ans[i] / 10
            ans[i] %= 10
            
        ans.reverse()
        
        if ans[0] == 0:
            ans.remove(0)
            
        return ''.join([str(i) for i in ans])
            
            