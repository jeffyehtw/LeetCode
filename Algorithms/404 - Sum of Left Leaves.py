# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
            
        return self.visitLeaves(root, False)
        
    def visitLeaves(self, node, is_left):
        # var
        left = 0
        right = 0
        
        if not node.left and not node.right:
            if is_left:
                return node.val
            else:
                return 0
        
        if node.left:
            left = self.visitLeaves(node.left, True) 
        if node.right:
            right = self.visitLeaves(node.right, False)
            
        return left + right
        