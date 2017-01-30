# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        head = ListNode(0)
        it = head
        
        while l1 and l2:
            if l1.val < l2.val:
                it.next = ListNode(l1.val)
                it = it.next
                l1 = l1.next
            elif l1.val > l2.val:
                it.next = ListNode(l2.val)
                it = it.next
                l2 = l2.next
            else:
                it.next = ListNode(l1.val)
                it = it.next
                it.next = ListNode(l2.val)
                it = it.next
                l1 = l1.next
                l2 = l2.next
        
        if l1 != None:
            it.next = l1
        elif l2 != None:
            it.next = l2
            
        return head.next