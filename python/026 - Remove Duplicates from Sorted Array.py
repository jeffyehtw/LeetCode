class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = set(nums)
        s = list(s)

        # adjust array size
        while len(nums):
            nums.pop()
        
        # readd
        for i in s:
            nums.append(i)
            
        nums.sort()
        
        return len(nums)