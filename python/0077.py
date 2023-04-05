class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        # generate list
        nums = range(1, n + 1)
        
        arr = itertools.combinations(nums, k)
        arr = list(arr)
        
        # fix format
        for i in range(0, len(arr)):
            arr[i] = list(arr[i])
        
        return arr