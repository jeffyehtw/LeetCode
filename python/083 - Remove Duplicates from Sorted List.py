# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
 
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #special case
        if head == None or head.next == None:
            return head
         
        #initialize
        front = ListNode(head.val)
        front = head
        index = ListNode(head.next.val)
        index = head.next
         
        while index:
            if index.val != front.val:
                front = index
                index = index.next
            else:
                front.next = index.next
                index = index.next
        return head