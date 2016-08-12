class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        zero = 0
        while 0 in nums:
            nums.remove(0)
            zero += 1

        while zero > 0:
            nums.append(0)
            zero -= 1