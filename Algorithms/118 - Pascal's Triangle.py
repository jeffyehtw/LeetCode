class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ans = []
        
        if numRows == 0:
            return []
        
        # row 1
        row = []
        row.append(1)
        ans.append(row)
        
        if numRows <= 1:
            return ans
        
        # row 2
        row = []
        row.append(1)
        row.append(1)
        ans.append(row)
        
        if numRows <= 2:
            return ans
            
        i = 2
        while i < numRows:
            j = 1
            row = [1]
            while j < i:
                row.append(ans[i - 1][j - 1] + ans[i - 1][j])
                j += 1
            row.append(1)
            ans.append(row)
            i += 1
        return ans
        
        