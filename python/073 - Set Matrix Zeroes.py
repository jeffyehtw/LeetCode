class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        # backup
        temp = [row[:] for row in matrix]
        
        # variables
        m = len(matrix)
        n = len(matrix[0])
        
        for i in range(0, m):
            for j in range(0, n):
                if temp[i][j] == 0:
                    # replace row
                    matrix[i] = [0] * n
                    # replace col
                    for k in range(0, m):
                        matrix[k][j] = 0