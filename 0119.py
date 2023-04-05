class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        ans = []
        
        # row 0
        row = []
        row.append(1)
        ans.append(row)
        if rowIndex == 0:
            return row
        
        # row 1
        row = []
        row.append(1)
        row.append(1)
        ans.append(row)
        
        if rowIndex == 1:
            return row
            
        i = 2
        while i <= rowIndex:
            j = 1
            row = [1]
            while j < i:
                row.append(ans[i - 1][j - 1] + ans[i - 1][j])
                j += 1
            row.append(1)
            ans.append(row)
            i += 1

        return row