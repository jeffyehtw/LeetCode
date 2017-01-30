class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ans = []
        for x in nums1:
            if x in nums2:
                nums2.remove(x)
                ans.append(x)
        return ans