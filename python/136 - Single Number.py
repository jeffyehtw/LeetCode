class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        if len(nums) == 0:
            return []
        elif len(nums) == 1:
            return nums[0]
        else:
            # is first
            if nums[0] != nums[1]:
                return nums[0]
            
            i = 2
            while i < len(nums) - 1:
                if nums[i] != nums[i + 1]:
                    return nums[i]
                i += 2
            return nums[len(nums) - 1]