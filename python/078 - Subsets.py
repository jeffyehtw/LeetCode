class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        arr = []
        for i in range(0, len(nums) + 1):
            temp = itertools.combinations(nums, i)
            temp = list(temp)
            arr += temp
        return arr