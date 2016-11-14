class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # bubble sort
        i = 0
        while i < len(nums) - 1:
            j = 0
            while j < len(nums) - 1 - i:
                if nums[j] > nums[j + 1]:
                    # swap
                    temp = nums[j]
                    nums[j] = nums[j + 1]
                    nums[j + 1] = temp
                j += 1
            i += 1