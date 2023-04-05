class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # variabels
        elements = []
        
        # init
        nums.sort()
        elements.append(Element(nums[0]))
        
        for i in nums:
            if elements[len(elements) - 1].val != i:
                elements.append(Element(i))
            elements[len(elements) - 1].count += 1
                
                
        elements.sort(key = lambda x: x.count, reverse = True)
        
        return [i.val for i in elements[0: k]]

class Element(object):
    def __init__(self, val):
        self.val = val
        self.count = 0