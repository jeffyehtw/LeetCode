class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = list(set(nums))
        nums.sort()
        n = len(nums)
        
        if n >= 3:
            return nums[n - 1 - 2]
        else:
            return nums[n - 1]