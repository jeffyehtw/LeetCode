class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 2:
            return len(nums)
        
        s = set(nums)
        s = list(s)
        
        for x in s:
            temp = [y for y in nums if y == x]
            print temp
            for i in range(0, len(temp) - 2):
                nums.remove(x)
        return len(nums)