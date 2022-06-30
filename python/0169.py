class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #initialize
        count = list()
        count.append(1)
         
        nums.sort()
         
        i = 1
        while i < len(nums):
            if nums[i] == nums[i - 1]:
                count.append(count[i - 1] + 1)
            else:
                count.append(1)
            #break condition
            if count[i] > len(nums) / 2:
                return nums[i]
            i += 1
        return nums[0]