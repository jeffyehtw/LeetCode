class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        arr = []
        for row in matrix:
            arr += row
        arr = sorted(arr)
        return arr[k - 1]