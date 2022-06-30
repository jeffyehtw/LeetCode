class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # length of nums
        n = len(nums)
        
        # abs shift offset
        offset = int(math.fabs(k))
        
        # backup nums
        temp = [num for num in nums]
        
        if k < 0:
            temp = temp[offset:] + temp[:offset]
        else:
            temp = temp[n - offset:] + temp[:n - offset]
            
        print temp
        
        # replace
        i = 0
        while i < n:
            nums[i] = temp[i]
            i += 1
            