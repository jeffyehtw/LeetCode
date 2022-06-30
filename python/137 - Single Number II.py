class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums)
        
        i = 0
        while i < len(nums):
            #last one
            if i == len(nums) - 1:
                return nums[i]
            # jump
            if nums[i] == nums[i + 1]:
                i += 2
            else:
                return nums[i]
            i += 1