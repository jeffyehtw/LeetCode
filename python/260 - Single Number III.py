class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums = sorted(nums)
        
        # return arr
        arr = []
        
        i = 0
        while i < len(nums) and len(arr) < 2:
            j = 1
            while i + j < len(nums):
                if nums[i] == nums[i + j]:
                    j += 1
                else:
                    break
            if j == 1:
                arr.append(nums[i])
            i += j
        return arr