class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        nums = [str(i) for i in range(0, n + 1)]
        
        # replace 3
        i = 3
        while i < len(nums):
            nums[i] = "Fizz"
            i += 3
            
        # replace 5
        i = 5
        while i < len(nums):
            if nums[i][0].isdigit():
                nums[i] = "Buzz"
            else:
                nums[i] += "Buzz"
            i += 5
                
        return nums[1:]