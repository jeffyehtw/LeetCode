# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        arr = []
        it = head
        
        while it:
            arr.append(it.val)
            it = it.next
        
        middle = len(arr) / 2
        for i in range(0, middle):
            if arr[i] != arr[len(arr) - 1 - i]:
                return False
        return True
            