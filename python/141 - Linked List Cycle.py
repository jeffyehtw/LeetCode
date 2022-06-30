# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        it = head
        s = set([])
        
        while it != None:
            if it in s:
                return True
            else:
                s.add(it)
            it = it.next
        return False
            