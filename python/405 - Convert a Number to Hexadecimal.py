class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if not num:
            return '0'
        
        # variables
        bin = []
        hex = []
        c = [str(i) for i in range (0, 10)]
        c += ['a', 'b', 'c', 'd', 'e', 'f']
        
        # num to bin
        bin = self.toBin(num)
        
        print bin
        
        i = 0
        while i < 8:
            index = 0
            index += bin[i * 4] * 8
            index += bin[i * 4 + 1] * 4
            index += bin[i * 4 + 2] * 2
            index += bin[i * 4 + 3]

            hex.append(c[index])
            i += 1
            
        index = 0
        while index < 8:
            if hex[index] != '0':
                break
            index += 1
        
        return "".join(str(i) for i in hex[index:])
        
        
    def toBin(self, num):
        # variables
        bits = []
        is_negative = num < 0
        
        num = int(math.fabs(num)) 
        
        while num > 0:
            bits.append(num % 2)
            num /= 2
        
        # fix length to 32
        fix_len = 32 - len(bits)
        for i in range(0, fix_len):
            bits.append(0)
        
        start = False
        if is_negative:
            for i in range(0, len(bits)):
                if not start and bits[i] == 1:
                    start = True
                elif start:
                    bits[i] = int(not bits[i])
                    
        return bits[::-1]