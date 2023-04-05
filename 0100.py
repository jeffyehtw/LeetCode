# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        _in = self.in_order(p) == self.in_order(q)
        _post = self.post_order(p) == self.post_order(q) 
        
        return _in and _post
    
    # LDR
    def in_order(self, head):
        # empty tree
        if head == None:
            return [None]
            
        # init
        visited = []
        
        visited += self.in_order(head.left)
        visited.append(head.val)
        visited += self.in_order(head.right)
    
        return visited
    
    # LRD
    def post_order(self, head):
        # empty tree
        if head == None:
            return [None]
            
        # init
        visited = []
        
        visited += self.post_order(head.left)
        visited += self.post_order(head.right)
        visited.append(head.val)
        
        return visited