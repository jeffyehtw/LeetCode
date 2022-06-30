class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        x = [int(i) for i in a]
        y = [int(i) for i in b]
        
        if len(x) < len(y):
            x = [0] * (len(y) - len(x)) + x
        elif len(x) > len(y):
            y = [0] * (len(x) - len(y)) + y
            
        print x
        print y
        
        # add
        z = []
        for i in range(0, len(x)):
            z.insert(0, x[i] + y[i])
            
        # fix
        for i in range(0, len(x) - 1):
            z[i + 1] += z[i] / 2
            z[i] %= 2
            
        z.reverse()
        
        while z[0] > 1:
            z.insert(0, z[0] / 2)
            z[1] %= 2
            

        return "".join(str(i) for i in z)