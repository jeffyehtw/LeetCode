class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dict = {}
        for i in range(0, len(nums)):
            key = str(nums[i])
            if key in dict:
                if i - dict[key] <= k:
                    return True
                else:
                    dict[key] = i
            else:
                dict[key] = i
        return False