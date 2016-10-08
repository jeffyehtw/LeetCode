# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        arr = []
        it = head
        
        while it:
            arr.append(it)
            it = it.next
        
        index = len(arr) - n

        if index == 0:
            head = head.next
        else:
            arr[index - 1].next = arr[index].next
        return head