class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        
        n = len(matrix)
        temp = [row[:] for row in matrix]
        
        for i in range(0, n):
            for j in range(0, n):
                matrix[j][n - 1 - i] = temp[i][j]