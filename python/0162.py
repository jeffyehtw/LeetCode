class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(0, len(nums) - 1):
            if nums[i] > nums[i + 1]:
                return i
        return len(nums) - 1
        