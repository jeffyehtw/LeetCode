# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        # empty list
        if not head:
            return head
        
        it = head
        prev = head
        while it:
            if it.val == val:
                if it == head:
                    head = head.next
                    prev = it
                    it = it.next
                elif not it.next:
                    prev.next = None
                    break
                else:
                    prev.next = it.next
                    it = it.next
            else:
                prev = it
                it = it.next
        return head