# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
 
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #variables
        temp = list()
         
        it = head
        while it:
            temp.append(it.val)
            it = it.next
         
        it = head
        index = len(temp) - 1
        while it:
            it.val = temp[index]
            it = it.next
            index -= 1
             
        return head